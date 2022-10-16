#include <bits/stdc++.h>
using namespace std;

#define db double
#define ll long long
#define ld long double
#define ull unsigned long long
#define vint vector <int>
#define vpii vector <pii>

#define pii pair <int,int>
#define fi first
#define se second
#define pb emplace_back
#define mem(x,v,s) memset(x,v,sizeof(x[0])*(s))
#define cpy(x,y,s) memcpy(x,y,sizeof(x[0])*(s))

inline int read(){
	int x=0; char s=getchar();
	while(!isdigit(s))s=getchar();
	while(isdigit(s))x=x*10+s-'0',s=getchar();
	return x;
}

#define exi puts("0"),exit(0)
const int N=1e6+5;
const ll mod=1e9+7;
int n,cnt,vis[N],pr[N],to[N],rev[N],c[N];
ll ans=1,turp[N],turn[N],fc[N],mul[N];
vint pfac[N];
int main(){
	cin>>n;
	for(int i=2;i<=n;i++)if(!vis[i]){
		pr[++cnt]=i,pfac[i].pb(i);
		for(int j=i<<1;j<=n;j+=i)vis[j]=1,pfac[j].pb(i);
	} pfac[1].pb(1),turp[1]=c[1]=1;
	for(int i=1;i<=n;i++){
		mul[i]=1;
		for(int it:pfac[i])mul[i]*=it;
		turn[mul[i]]++;
	} for(int i=1;i<=cnt;i++)turp[c[pr[i]]=n/pr[i]]++;
	for(int i=1,a;i<=n;i++){
		cin>>a; if(!a)continue;
		if(pfac[i].size()!=pfac[a].size())exi;
		for(int j=0;j<pfac[i].size();j++)
			if(c[pfac[i][j]]!=c[pfac[a][j]])exi;
		int x=pfac[i].back(),y=pfac[a].back();
		if(to[x]&&to[x]!=y||rev[y]&&rev[y]!=x)exi;
		turp[c[x]]-=!to[x],to[x]=y,rev[y]=x,turn[mul[a]]--;
	} fc[0]=1;
	for(int i=1;i<=n;i++)fc[i]=fc[i-1]*i%mod;
	for(int i=1;i<=n;i++)ans=ans*fc[turn[i]]%mod*fc[turp[i]]%mod;
	cout<<ans<<endl; 
	return 0;
}
////