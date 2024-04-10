#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=2.1e5;
int n,m,k;
int a[N],b[N];
vector<int> ve[N];
double c[N];
struct re{
	int a;
	double b;
}id[N];
int pp[N];
bool cmp(re x,re y)
{
//	cerr<<id[x]<<" "<<id[y]<<" "<<c[id[x]]<<" "<<c[id[y]]<<endl;
//	return c[id[x]]>c[id[y]];  
    return x.b>y.b;
}
int main()
{
	ios::sync_with_stdio(false);
    cin>>n;
    int nn=2e5;
    rep(i,1,n) cin>>a[i]>>b[i],ve[a[i]].push_back(b[i]);
    double ans=0;
    int da=0;
    rep(i,1,20)
    {
    	rep(j,1,nn)
    	{
    		c[j]=0;
    		for(auto v:ve[j])
    		{
    			c[j]+=min(1.0,1.0*v/i);
        	}
    	}
    	rep(j,1,nn) id[j]={j,c[j]};
    	sort(id+1,id+nn+1,cmp);
    	double now=0;
    	rep(j,1,i) now+=id[j].b;
    	if (now>ans)
    	{
    		ans=now;
    		da=i;
    		rep(j,1,i) pp[j]=id[j].a;
    	}
    }
    rep(j,1,nn)
    {
    	c[j]=0;
    	for (auto v:ve[j]) c[j]+=v;
        id[j]={j,c[j]};
    }
    sort(id+1,id+nn+1,cmp);
    double now=0;
    rep(i,1,20) now+=id[i].b;
    rep(i,21,nn)
    {
    	now+=id[i].b;
    	if (now/i>ans)
    	{
    		ans=now/i;
    		da=i;
    	}
    }
    if (da>20)
    {
    	rep(i,1,da) pp[i]=id[i].a;
    }
    cout<<da<<endl;
    rep(i,1,da) cout<<pp[i]<<" ";
    cout<<endl;
	return 0; 
}