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
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=500010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans, sum, ans2;
ll A[MAXN], B[MAXN], n1, n2;
ll ps[MAXN], ps2[MAXN], ps3[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	k++;
	for (int i=1; i<=n; i++){
		cin>>x;
		if (x>=0) A[n1++]=x;
		else B[n2++]=x;
	}
	sort(A, A+n1);
	sort(B, B+n2);
	for (int i=0; i<n1; i++) ans+=i*A[i], sum+=A[i];
	
	for (int i=1; i<=n2; i++) ps[i]=((i-1)/k)*B[i-1] + ps[i-1];
	for (int i=1; i<=n2; i++) ps2[i]=ps2[i-1] + B[i-1];
	for (int i=1; i<=n2; i++) ps3[i]=ps3[i-1] + B[i-1]*(i-1);
	
	ans2=-INF;
	for (int t=0; t<=n2; t++){
		ll res=ps[t];
		
		ll st=t/k;
		res+=(st+n2-t)*sum;
		res+=(st-t)*(ps2[n2]-ps2[t]);
		res+=ps3[n2]-ps3[t];
		ans2=max(ans2, res);
	
	}
	
	ans+=ans2;
	cout<<ans<<"\n";
	
	return 0;
}