#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=4e5;
struct re{
	int a,b,c,id;
}a[N],b[N];
int n,m,jl[N];
bool cmp(re x,re y)
{
	if (x.a+x.b-x.c!=y.a+y.b-y.c) 
	  return x.a+x.b-x.c<y.a+y.b-y.c;
	return x.a>y.a;
}
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		rep(i,1,n)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].id=i;
			b[i]=a[i];
		}
		sort(a+1,a+n+1,cmp);
		int j=0;
		int ans=0;
		for (int i=1;i<=n;i=j+1)
		{
			for (j=i;j<=n;j++) if (a[i].a+a[i].b-a[i].c!=a[j].a+a[j].b-a[j].c) break;
			j--; 
			int mn=0,lst=i;
			rep(k,i,j)
			{
			  if (mn>a[k].a)
			  {
			  	rep(i,lst,k-1) jl[a[i].id]=mn;
			  	lst=k;
			  	ans++; mn=max(a[k].a-a[k].c,0);
			  }
			  mn=max(mn,a[k].a-a[k].c);
		    }
		    ans++;
		    rep(i,lst,j) jl[a[i].id]=mn;
		}
		cout<<ans<<"\n";
		rep(i,1,n)
		  cout<<b[i].a-jl[i]<<" "<<(b[i].c-(b[i].a-jl[i]))<<"\n";
    }
	return 0; 
}