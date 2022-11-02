#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
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

const int N=201000;
int n,k,m,_;
bool b[N];
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d%d",&n,&k,&m);
		rep(i,1,n+1) b[i]=0;
		rep(i,0,m) {
			int x;
			scanf("%d",&x);
			b[x]=1;
		}
		int c0=n-m;
		if (c0%(k-1)!=0) {
			puts("NO");
			continue;
		}
		bool valid=(c0==0);
		int cc=0;
		rep(i,1,n+1) {
			if (b[i]==0) cc++; else {
				valid|=(cc>=k/2)&&(cc<=c0-k/2);
			}
		}
		puts(valid?"YES":"NO");
	}
}