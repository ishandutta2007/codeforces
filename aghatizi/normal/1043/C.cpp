#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e3 + 20;

string dp[maxn][2];

int par[maxn][2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	int n = s.size();

	for(int i = 1; i <= n; i++)
	{
		char ch = s[i - 1];

		string A = ch + dp[i - 1][1] , B = dp[i - 1][0] + ch;
		if(A < B)
		{
			dp[i][0] = dp[i][1] = A;
			par[i][0] = par[i][1] = 1;
		}
		else
		{
			dp[i][0] = dp[i][1] = B;
			par[i][0] = par[i][1] = 0;
		}
	}

	int A = n , B = 0;

	vector<int> res;
	while(A > 0)
	{
		res.pb(B ^ par[A][B]);
		B = par[A][B];
		A--;
	}

	reverse(res.begin() , res.end());
	for(auto x : res)
		cout << x << " ";
	cout << endl;
}