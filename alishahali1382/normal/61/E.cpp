#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
const int MAXN = 1000010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
int ind[MAXN];
int B[MAXN];
ll L[MAXN];
ll R[MAXN];

void Sort(int l, int r){
	if (r-l<=1) return ;
	int mid=(l+r)>>1;
	Sort(l, mid);
	Sort(mid, r);
	for (int i=l; i<r; i++) B[i]=ind[i];
	int j=mid, pos=l;
	for (int i=l; i<mid; i++){
		while (j<r && A[B[j]]<A[B[i]]){
			ind[pos++]=B[j];
			L[B[j]]+=mid-i;
			j++;
		}
		ind[pos++]=B[i];
		R[B[i]]+=j-mid;
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], ind[i]=i;
	Sort(1, n+1);
	for (int i=1; i<=n; i++) ans+=L[i]*R[i];
	cout<<ans<<'\n';
	
	return 0;
}