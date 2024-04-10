#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

string a,b;

int main()
{jizz
	int n,ans;
	cin >> n >> a >> b;
	if((n&1) && a[n/2]!=b[n/2]) ans=1;
	else ans=0;
	for(int i=0,j=n-1;i<j;++i,--j)
	{
		string s="";
		s.pb(a[i]),s.pb(a[j]),s.pb(b[i]),s.pb(b[j]);
		sort(s.begin(),s.end());
		if(s[0]==s[1] && s[2]==s[3]);
		else if(a[i]==b[j] || a[i]==b[i] || b[i]==b[j] || a[j]==b[i] || a[j]==b[j]) ++ans;
		else ans+=2;
	}
	cout << ans << "\n";
}