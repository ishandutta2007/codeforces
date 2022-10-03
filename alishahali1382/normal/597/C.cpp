#include <bits/stdc++.h>
#pragma GCC optimize ("O2")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll A[MAXN];
ll fen[11][MAXN];

void add(ll BIT[], int id, ll x){ for (; id<MAXN; id+=id&-id) BIT[id]+=x;}
ll get(ll BIT[], int id){
	ll res=0;
	for (; id; id-=id&-id) res+=BIT[id];
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		add(fen[0], A[i], 1);
		for (int j=1; j<=k; j++) add(fen[j], A[i], get(fen[j-1], A[i]-1));
	}
	cout<<get(fen[k], n)<<'\n';
	
	return 0;
}