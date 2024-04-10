#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
const int N=1e6;
int n,m;
char s[N];
int a[N],b[N],cnt[N];
bool h[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n;
		rep(i,1,n) cin>>a[i];
		rep(i,1,n) cin>>b[i];
		bool tt=1;
		int now=n;
		rep(i,1,n) cnt[i]=0;
		dep(i,n,1)
		{
			if (cnt[a[i]]>=0&&a[i]!=b[now]) tt=0; cnt[a[i]]++;
		    while (a[i]==b[now]) cnt[b[now]]--,now--;
	    }
	    if (tt&&now==0) cout<<"YES"<<endl;
		else cout<<"NO"<<endl; 
	}
	return 0;
}