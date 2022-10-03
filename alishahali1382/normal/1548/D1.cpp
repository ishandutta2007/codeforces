#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define SZ(x) ((int)x.size())
#define get(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
ll cnt[4], ans;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	ans=1ll*n*(n-1)*(n-2)/6;
	for (int i=0; i<n; i++){
		cin>>x>>y;
		x>>=1;
		y>>=1;
		x&=1;
		y&=1;
//		debug2(x, y)
		cnt[2*x+y]++;
	}
	for (int a=0; a<4; a++){
		for (int b=a+1; b<4; b++){
			for (int c=b+1; c<4; c++){
				int ax=get(a, 1), ay=get(a, 0);
				int bx=get(b, 1), by=get(b, 0);
				int cx=get(c, 1), cy=get(c, 0);
				int tmp=__gcd(ax-bx, ay-by)+__gcd(ax-cx, ay-cy)+__gcd(bx-cx, by-cy);
				if (tmp&1) ans-=cnt[a]*cnt[b]*cnt[c];
			}
		}
	} 
	cout<<ans<<"\n";
	
	return 0;
}