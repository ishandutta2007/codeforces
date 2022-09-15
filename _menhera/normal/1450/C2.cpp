#include<bits/stdc++.h>
using namespace std;
int x[101010], y[101010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while(T--)
	{
		int N; cin >> N;
		vector<string> V;
		for(int i=0; i<N; ++i)
		{
			string s; cin >> s; V.push_back(s);
		}
		vector<int> cnt1(3), cnt2(3);
		for(int i=0; i<N; ++i)
		{
			for(int j=0; j<N; ++j)
			{
				int t = (i+j)%3;
				if(V[i][j] == 'X') ++cnt1[t];
				if(V[i][j] == 'O') ++cnt2[t];
			}
		}
		vector<int> v = {cnt1[0]+cnt2[1], cnt1[1]+cnt2[2], cnt1[2]+cnt2[0]};
		int x = min_element(v.begin(), v.end())-v.begin();
		int c = 0;
		for(int i=0; i<N; ++i)
		{
			for(int j=0; j<N; ++j)
			{
				int t1 = (i+j)%3, t2=(i+j+2)%3;
				if(V[i][j] == 'X' && t1 == x)
				{
					cout << 'O';
					++c;
				}
				else if(V[i][j] == 'O' && t2 == x)
				{
					cout << 'X';
					++c;
				}
				else cout << V[i][j];
			}
			cout << endl;
		}
		assert(v[x] == c);
	}
}