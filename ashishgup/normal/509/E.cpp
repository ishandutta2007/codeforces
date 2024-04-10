#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N=5e5+5;

int n;
double cur=0, ans=0;
string s;
int pref[N], dpref[N];

int isvowel(char ch)
{
	return (ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'||ch=='Y');
}

int32_t main()
{
	IOS;
	cin>>s;
	n=s.size();
	for(int i=1;i<=n;i++)
	{
		pref[i]=pref[i-1] + (isvowel(s[i-1]));
		dpref[i]=dpref[i-1] + pref[i];
	}
	for(int i=1;i<=n;i++)
	{
		double num=(dpref[n] - dpref[i-1]) - (dpref[n-i]);
		double den=i;
		ans+=num/den;
	}
	cout<<fixed<<setprecision(12)<<ans;
	return 0;
}