#include <bits/stdc++.h>
using namespace std;
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
template<typename T>
void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=2e5;
int n,mn[MAXN+1000];
bool vis[MAXN+5];
void solve(){
	scanf("%d",&n);
	vis[n]=1;int cur=n;
	vector<int> v;
	while(cur!=2){v.pb(cur);vis[cur]=1;cur=mn[cur];}
	v.pb(2);vis[2]=1;
	printf("%d\n",n-1-v.size()+int(v.size()-1)*2);
	for(int i=3;i<=n;i++) if(!vis[i]) printf("%d %d\n",i,n);
	for(int i=0;i<(int)(v.size()-1);i++){
		printf("%d %d\n",v[i],v[i+1]);
		printf("%d %d\n",v[i],v[i+1]);
	}
	ffe(it,v) vis[*it]=0;
}
signed main(){
	for(int i=1;i<=448;i++) for(int j=(i-1)*(i-1)+1;j<=i*i;j++) mn[j]=i;
	int qu;scanf("%d",&qu);while(qu--) solve();
	return 0;
}