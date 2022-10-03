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
#define kill(x) return cout<<x<<'\n', 0;
#define getbit(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=100010, SQ=320;

int n, m, k, u, v, x, y, t, a, b, ans=1;
int A[MAXN], B[MAXN];
int mark[2*MAXN], cnt[2*MAXN];
vector<int> diff;

void Check(int d){
	for (int i=1; i<=n; i++) B[i]=A[i]-i*d;
	sort(B+1, B+n+1);
	int cnt=1;
	for (int i=2; i<=n; i++){
		if (B[i]!=B[i-1]) cnt=0;
		cnt++;
		ans=max(ans, cnt);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	
	Check(0);
	for (int i=1; i<=SQ; i++){
		Check(i);
		Check(-i);
	}
	for (int i=1; i<=n; i++){
		for (int j=i+1; j<=n && (j-i)*SQ<=100000; j++){
			int x=A[j]-A[i], y=j-i;
			if (x%y==0){
				x/=y;
				x+=MAXN;
				if (mark[x]!=i) mark[x]=i, cnt[x]=0;
				cnt[x]++;
				ans=max(ans, cnt[x]+1);
			}
		}
	}
	
	debug(ans)
	cout<<n-ans<<"\n";
	
	return 0;
}