#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
const int N=5e5;
int n,q,mo,cnt,f[N],a[N],b[N];
inline void gao(int x,int y)
{
	if (x>n) return;
	if (!a[x]) cnt--;
	(a[x]+=y)%=mo;
	if (!a[x]) cnt++;
}
signed main()
{
//	freopen("1.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q>>mo;
	rep(i,1,n) cin>>a[i];
	rep(i,1,n) cin>>b[i];
	rep(i,1,n) a[i]=(a[i]-b[i])%mo;
	dep(i,n,2)
	{ 
	  a[i]=((a[i]-a[i-1])%mo-a[i-2])%mo;
	  if (!a[i]) cnt++;
    }
    if (!a[1]) cnt++;
    f[1]=1; f[2]=1;
    rep(i,3,n+1) f[i]=(f[i-1]+f[i-2])%mo;
    while (q--)
    {
    	char c[10]; 
    	int l,r;
    	cin>>c>>l>>r;
    	if (c[0]=='A')
    	{
    		gao(l,1);
    		gao(r+1,-f[r-l+2]);
    		gao(r+2,-f[r-l+1]);
    	} else
    	{
    		gao(l,-1);
    		gao(r+1,f[r-l+2]);
    		gao(r+2,f[r-l+1]);
        }
        if (cnt==n) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n"; 
    }
	return 0; 
}