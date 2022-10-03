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
const int MAXN=1000010, LOG=20;

ll ans; // :))
int n, m, k, u, v, x, y, t, a, b;
int A[MAXN], cnt[MAXN], todo[MAXN], tdo;

void divide(int tl, int tr){
	if (tr-tl==1) return ;
	int mid=(tl+tr)>>1;
	divide(tl, mid);
	divide(mid, tr);
	int sum=0, mx=0, j=mid, sum2=0;
	for (int i=mid-1; i>=tl; i--){
		mx=max(mx, A[i]);
		sum=(sum + A[i])%k;
		while (j<tr && A[j]<=mx){
			sum2=(sum2 + A[j++])%k;
			todo[tdo++]=sum2;
			cnt[sum2]++;
		}
		ans+=cnt[(k-sum+mx)%k];
	}
	while (tdo) cnt[todo[--tdo]]=0;
	
	sum=0, mx=0, j=mid-1, sum2=0;
	for (int i=mid; i<tr; i++){
		mx=max(mx, A[i]);
		sum=(sum + A[i])%k;
		while (tl<=j && A[j]<mx){
			sum2=(sum2 + A[j--])%k;
			todo[tdo++]=sum2;
			cnt[sum2]++;
		}
		ans+=cnt[(k-sum+mx)%k];
	}
	while (tdo) cnt[todo[--tdo]]=0;
	
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++) cin>>A[i];
	divide(1, n+1);
	cout<<ans<<"\n";
	
	return 0;
}