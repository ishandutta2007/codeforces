#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
#define me(x) memset(x,0,sizeof(x))
#define IL inline
#define rint register int
char ss[1<<24],*A=ss,*B=ss;
IL char gc()
{
	return A==B&&(B=(A=ss)+fread(ss,1,1<<24,stdin),A==B)?EOF:*A++;
}
template<class T>void read(T &x)
{
	int f=1,c; while (c=gc(),c<48||c>57) if (c=='-') f=-1; x=(c^48);
	while(c=gc(),c>47&&c<58) x=x*10+(c^48); x*=f;
}
const int N=2e5;
int a[N],cnt[N],f[N];
vector<int> ve[N];
struct re{
	int a,b;
};
struct cmp{
	bool operator () (re x,re y)
	{
		return x.a<y.a;
	}
};
priority_queue<re,vector<re>,cmp> Q;
int main()
{
	ios::sync_with_stdio(false);
	int T,n,x,y;
	cin>>T;
	while(T--)
	{
	    while (!Q.empty()) Q.pop(); 
		int jl=0;
		cin>>n>>x>>y; y-=x;
		rep(i,1,n+1) cnt[i]=0,ve[i].clear(),f[i]=0;
		rep(i,1,n) cin>>a[i],cnt[a[i]]++,ve[a[i]].push_back(i);
		rep(i,1,n+1) if (!cnt[i]) jl=i; 
		rep(i,1,n+1)
		{
			if (cnt[i]) Q.push((re){cnt[i],i});
		}
		rep(i,1,x)
		{
			re x=Q.top(); Q.pop();
			int t=ve[x.b][cnt[x.b]-1]; f[t]=a[t];
			cnt[x.b]--; 
			if (cnt[x.b]) Q.push((re){cnt[x.b],x.b});
	    }
	    int ans=0,ans2=0;
	    rep(i,1,n+1) ans+=cnt[i],ans2=max(ans2,cnt[i]);
	    int k=min(ans,2*(ans-ans2));
	    if (y<=k)
		{
			int yy=y;
			for (int i=1;i<=y;i+=2)
			{
				if (y-i==2&&Q.size()>2)
				{
					re x=Q.top(); Q.pop(); re y=Q.top(); Q.pop();
						re z=Q.top(); Q.pop();
						int t1=ve[x.b][cnt[x.b]-1];
				        int t2=ve[y.b][cnt[y.b]-1];
						int t3=ve[z.b][cnt[z.b]-1];
						f[t1]=a[t2]; f[t2]=a[t3]; f[t3]=a[t1];
						break;
				}
				re x=Q.top(); Q.pop(); re y=Q.top(); Q.pop();
				int t1=ve[x.b][cnt[x.b]-1];
				int t2=ve[y.b][cnt[y.b]-1];
				f[t1]=a[t2]; if (i!=yy) f[t2]=a[t1];
				cnt[x.b]--; cnt[y.b]--;
				if (cnt[x.b]) Q.push((re){cnt[x.b],x.b}); 
				if (cnt[y.b]) Q.push((re){cnt[y.b],y.b});
			}
			cout<<"YES"<<endl;
			rep(i,1,n) if (f[i])
			{
				cout<<f[i]<<" ";
			} else cout<<jl<<" ";
			cout<<endl;
	    } else cout<<"NO"<<endl;
    }
	return 0; 
}