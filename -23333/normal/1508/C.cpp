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
template<class T>void maxa(T &x,T y)
{
	if (y>x) x=y;
}
template<class T>void mina(T &x,T y)
{
	if (y<x) x=y;
}
template<class T>void read(T &x)
{
	int f=1,c; while (c=gc(),c<48||c>57) if (c=='-') f=-1; x=(c^48);
	while(c=gc(),c>47&&c<58) x=x*10+(c^48); x*=f;
}
const int mo=1e9+7;
const int N=5e5;
struct re{
	int a,b,c;
}e[N*2];
vector<re> ve1;
int head[N],fa[N],fa2[N],l;
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int find2(int x)
{
	return fa2[x]==x?x:fa2[x]=find2(fa2[x]);
}
void arr(int x,int y,int z)
{
	e[++l].a=head[x];
	e[l].b=y;
	e[l].c=z;
	head[x]=l;
}
struct li{int pre, nxt; }L[N];
bool vis1[N], vis2[N]; 
int scc[N];
void del(int x){
    L[L[x].pre].nxt = L[x].nxt;
    L[L[x].nxt].pre = L[x].pre;
}
queue <int> q;
void bfs(){
    while(L[0].nxt){
    	vector<int> ve;
        int now = L[0].nxt, curscc = 1;
        ve.push_back(now);
        del(now);
        q.push(now);
        vis2[now] = 1;
        while(!q.empty()){
            int x = q.front(); q.pop();
            for(int u = head[x]; u; u=e[u].a) vis1[e[u].b] = 1;
            for(int i = L[0].nxt; i; i = L[i].nxt){
                if(!vis1[i] && !vis2[i]){
                    vis2[i] = 1;
                    q.push(i);
                    ve.push_back(i);
                    del(i);
                }
            }
            for(int u = head[x]; u; u=e[u].a) vis1[e[u].b] = 0; 
        }
        int lst=0;
        for (auto i:ve)
        {
        	if (lst)
        	{
        //		cerr<<lst<<" "<<i<<endl;
        		int f1=find(lst),f2=find(i);
        		if (f1!=f2) fa[f1]=f2;
        	}
        	lst=i;
        }
    }
}
bool cmp(re x,re y)
{
	return x.c<y.c;
}
int main(){
	int n,m;
    cin>>n>>m;
    ll ans=0;
    rep(i,1,m)
    {
    	int x,y,z;
    	cin>>x>>y>>z;
    	arr(y,x,z);
    	arr(x,y,z);
    	ve1.push_back((re){x,y,z});
	    ans^=z; 
    }
    for(int i = 1; i <= n; i++){
        L[i-1].nxt = i; L[i].pre = i - 1;
    } L[n].nxt = 0;
    rep(i,1,n) fa[i]=i,fa2[i]=i;
    bfs();
    ll nn=1ll*n*(n-1)/2;
    int cnt=0;
    rep(i,1,n) if (fa[i]!=i) cnt++;
    sort(ve1.begin(),ve1.end(),cmp);
    ll ans2=0,ans3=1e18;
    for (auto i:ve1)
    {
    	int x=i.b,y=i.a;
    	int f1=find(x),f2=find(y);
    	if(f1!=f2)
    	{
    		fa[f1]=f2; ans2+=i.c;
    		int f1=find2(x),f2=find2(y);
    		fa2[f1]=f2;
    	} else 
		{
		  if(find2(x)!=find2(y)) ans3=min(ans3,1ll*i.c);
	    }
    }
    if (cnt+m==nn)
    {
    	cout<<min(ans,ans3)+ans2<<endl;
    } else cout<<ans2<<endl;
    return 0;
}