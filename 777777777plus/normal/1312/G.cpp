#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define Rep(i,a,n) for (int i=a;i<=n;i++)
#define Per(i,a,n) for (int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head
const int maxn = 1e6+10;
const int INF = 1e9;
int a[maxn],b[maxn],s[maxn],s1[maxn],q[maxn],t[maxn][26];
void dfs(int x){
    if(s[x])a[x]=min(a[x],b[x]+1);
    b[x]=min(b[x],a[x]);
    rep(i,0,26)if(t[x][i]){
        a[t[x][i]]=min(a[t[x][i]],a[x]+1);
        b[t[x][i]]=min(b[t[x][i]],b[x]+s[x]);
        dfs(t[x][i]);
        s[x]+=s[t[x][i]];
    }
}
signed main(){
    int n;scanf("%d",&n);
    rep(i,1,n+1){
        int x;char c[2];
        scanf("%d %s",&x,c);
        t[x][c[0]-'a']=i;
    }
    int m;scanf("%d",&m);
    rep(i,1,m+1){
        scanf("%d",&q[i]);
        s[q[i]]=s1[q[i]]=1;
    }
    memset(a,0x3f,sizeof(a));
    memset(b,0x3f,sizeof(b));
    a[0]=b[0]=0;
    dfs(0);
    rep(i,1,m+1) printf("%d ",a[q[i]]);
    return 0;
}