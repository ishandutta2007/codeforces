#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e2 + 20;
const int maxk = 4,w1=25,w2=15;

pair<int,int> dp[maxn][maxn][maxk][maxk];

inline void upd(int i , int j , int st1 , int st2 , int ii , int jj , int st11 , int st22)
{
	if(0 <= ii && 0 <= jj && 0 <= st11 && 0 <= st22 && dp[ii][jj][st11][st22].first > -1)
	{
		bool f = 1;

		if(st1 == 3 && st11 == 3)
			f = 0;
		if(st2 == 3 && st22 == 3)
			f = 0;
		if(f)
			dp[i][j][st1][st2] = make_pair(ii , jj);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxn; j++)
			for(int k = 0; k < maxk; k++)
				for(int l = 0; l < maxk; l++)
					dp[i][j][k][l] = {-1 , -1};
	
	dp[0][0][0][0] = {0,0};
	for(int i = 0; i < maxn - 10; i++)
		for(int j = 0; j < maxn - 10; j++)
			for(int st1 = 0; st1 <= 3; st1++)
				for(int st2 = 0; st1 + st2 <= 5 && st2 <= 3; st2++)
				{
					if(st1 + st2 == 5)
					{
						for(int pt1 = 0; pt1 <= w2; pt1++)
							for(int pt2 = (pt1 == w2? 0 : w2); pt2 <= w2; pt2++)
							{
								if(pt2 - pt1 > 1)
									upd(i , j , st1 , st2 , i - pt1 , j - pt2 , st1 , st2 - 1);
								if(pt1 - pt2 > 1)
									upd(i , j , st1 , st2 , i - pt1 , j - pt2 , st1 - 1 , st2);
							}

						for(int pt1 = w2 - 1; pt1 <= i; pt1++)
						{
							upd(i , j , st1 , st2 , i - pt1 , j - pt1 - 2 , st1 , st2 - 1);

							if(pt1 >= w2)
								upd(i , j , st1 , st2 , i - pt1 , j - pt1 + 2 , st1 - 1 , st2);
						}
					}
					else
					{
						for(int pt1 = 0; pt1 <= w1; pt1++)
							for(int pt2 = (pt1 == w1? 0 : w1); pt2 <= w1; pt2++)
							{
								if(pt2 - pt1 > 1)
									upd(i , j , st1 , st2 , i - pt1 , j - pt2 , st1 , st2 - 1);
								if(pt1 - pt2 > 1)
									upd(i , j , st1 , st2 , i - pt1 , j - pt2 , st1 - 1 , st2);
							}

						for(int pt1 = w1 - 1; pt1 <= i; pt1++)
						{
							upd(i , j , st1 , st2 , i - pt1 , j - pt1 - 2 , st1 , st2 - 1);

							if(pt1 >= w1)
								upd(i , j , st1 , st2 , i - pt1 , j - pt1 + 2 , st1 - 1 , st2);
						}
					}
				}

	int q;
	cin >> q;

	while(q--)
	{
		pair<int , vector<pair<int , int> > > ans , tmp;
		ans.first = tmp.first = -1e9;
		ans.second = tmp.second = {};

		int resa = 0 , resb = 0;

		int a , b;
		cin >> a >> b;

		for(int i = 0; i <= 3; i++)
			for(int j = (i == 3? 0 : 3); j <= 3; j++)
				if(i != j && dp[a][b][i][j].first >= 0)
				{
					int ta = a , tb = b , ti = i , tj = j;

					auto k = tmp;
					while(ti || tj)
					{
						int aa = dp[ta][tb][ti][tj].first , bb = dp[ta][tb][ti][tj].second;
						k.second.pb(make_pair(ta - aa , tb - bb));

						if(ta - aa > tb - bb)
							ti--;
						else
							tj--;

						ta = aa;
						tb = bb;
					}

					k.first = i - j;

					if(ans < k)
					{
						resa = i;
						resb = j;
						ans = k;
					}
				}

		if(ans.first < -1e5)
			cout << "Impossible" << endl;
		else
		{
			cout << resa << ":" << resb << endl;

			reverse(ans.second.begin() , ans.second.end());
			for(auto x : ans.second)
				cout << x.first << ":" << x.second << " ";
			cout << endl;
		}
	}
}