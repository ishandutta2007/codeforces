#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define ALL(v) v.begin(),v.end()
#define MEM(i,j) memset(i,j,sizeof i)
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

string s;
int ans[1005];

int main()
{jizz
	int t=0;
	cin >> s;
	for(int i=s.size()-1;i>=0;--i)
		if(t)
			if(s[i]=='b') ans[i]=1,t^=1;
			else ans[i]=0;
		else
			if(s[i]=='a') ans[i]=1,t^=1;
			else ans[i]=0;
	for(int i=0;i<s.size();++i)
		cout << ans[i] << " ";
	ET;
}