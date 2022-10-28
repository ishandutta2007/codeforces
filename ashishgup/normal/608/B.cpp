
 #include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, m, ans=0;
string a, b;
int pref[N], pref0[N];

int32_t main()
{
	IOS;
	cin>>a>>b;
	n=a.size(), m=b.size();
	a="*"+a;
	b="*"+b;
	for(int i=1;i<=m;i++)
	{
		pref[i]=(pref[i-1]+(b[i]=='1'));
		pref0[i]=(pref0[i-1]+(b[i]=='0'));
	}
	for(int i=1;i<=n;i++)
	{
		int last=m-n+i;
		if(a[i]=='0')
			ans+=pref[last]-pref[i-1];
		else
			ans+=pref0[last]-pref0[i-1];
	}
	cout<<ans;
	return 0;
}