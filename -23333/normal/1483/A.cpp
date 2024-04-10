#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
#define me(x) memset(x,0,sizeof(x))
#define IL inline
#define rint register int
inline ll rd(){
	ll x=0;char c=getchar();bool f=0;
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f?-x:x;
}
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
const int mo=1e9+7;
struct re{
	int a,b,c;
};
const int N=5e5;
vector<int> ve[N];
int a[N],p[N];
int main()
{
   ios::sync_with_stdio(false);
   int T;
   cin>>T;
   while (T--)
   {
   	int n,m;
   	cin>>n>>m;
   	rep(i,1,m)
   	{
   		int x;
   		cin>>x;
   		ve[i].clear();
   		ve[i].push_back(x);
   		rep(j,1,ve[i][0])
   		{
   		  cin>>x;
   		  ve[i].push_back(x);
   	    }
   	    p[ve[i][1]]++;
   	}
   	int ans=0;
   	int kk=(m+1)/2;
   	rep(i,1,n) if (p[i]>kk) ans=i;
   	int now=p[ans];
   	rep(i,1,m) a[i]=0;
   	rep(i,1,m)
   	{
   	  if (ve[i][1]==ans)
   	  {
   	    if (ve[i][0]>=2) a[i]=ve[i][2],now--;
   	    else a[i]=ve[i][1];
   	  } else a[i]=ve[i][1];
   	  if (now<=kk) break;
    }
    rep(i,1,m) if (!a[i]) a[i]=ve[i][1];
    if (now<=kk)
    {
    	cout<<"YES"<<endl;
    	rep(i,1,m) cout<<a[i]<<" ";
    	cout<<endl;
    } else cout<<"NO"<<endl;
   	rep(i,1,n) p[i]=0;
   }
   return 0;
}