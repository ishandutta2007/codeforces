#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=4e5;
int n,m;
char s[N];
int cnt[30];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		cin>>s;
		int n=strlen(s);
		rep(i,0,n-1) cnt[s[i]-'a']++;
		int pos=0;
		rep(i,0,n-1)
		{
		  if (cnt[s[i]-'a']==1) { pos=i; break;}
		  cnt[s[i]-'a']--;
	    }
		rep(i,pos,n-1) cout<<s[i];
		cout<<"\n";
		rep(i,0,29) cnt[i]=0;
    }
	return 0;
}