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
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=600010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans=inf;
int A[MAXN], B[6];
pii C[MAXN];
int cnt[MAXN], bad;

inline void add(int x, int w){
	bad-=(cnt[x]==0);
	cnt[x]+=w;
	bad+=(cnt[x]==0);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=0; i<6; i++) cin>>B[i];
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>A[i];
		for (int j=0; j<6; j++) C[6*i+j]={A[i]-B[j], i};
	}
	sort(C, C+6*n);
	bad=n;
	int j=0;
	for (int i=0; i<6*n; i++){
		add(C[i].second, +1);
		while (!bad){
			add(C[j].second, -1);
			if (bad){
				add(C[j].second, +1);
				break ;
			}
			j++;
		}
		if (!bad){
			ans=min(ans, C[i].first-C[j].first);
		}
	}
	cout<<ans<<"\n";
	
	return 0;
}