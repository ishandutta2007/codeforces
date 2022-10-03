#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

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
const int MAXN = 200010, LOG=18;

int n, m, k, u, v, x, y, t, a, b, ans, cycle;
int A[MAXN*2];
pii SP[MAXN][LOG];

int RMQ(int l, int r){
	int lg=log2(r-l);
	return min(SP[l][lg], SP[r-(1<<lg)][lg]).second;
}

int get(int tl, int tr){
	if (tr<=tl) return 0;
	if (tr-tl==1) return 1;
	int mid=RMQ(tl, tr);
	return max(get(tl, mid), get(mid+1, tr))+1;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	if (n<=2){
		cout<<n<<" 0\n";
		return 0;
	}
	for (int i=0; i<n; i++){
		cin>>A[i];
		if (A[i]==1) cycle=i;
	}
	for (int i=0; i<n; i++) A[i+n]=A[i];
	for (int i=0; i<n; i++) A[i]=A[n+((i+cycle)%n)];
	
	for (int i=0; i<n; i++) SP[i][0]={A[i], i};
	for (int j=1; j<LOG; j++) for (int i=0; i+(1<<j)<=n; i++) SP[i][j]=min(SP[i][j-1], SP[i+(1<<j-1)][j-1]);
	
	int dwn=0, up=n;
	while (up-dwn>1){
		int mid=(dwn+up)>>1;
		if (get(1, mid)>get(mid, n)) up=mid;
		else dwn=mid;
	}
	// [1, dwn)    [dwn, n)
	
	int ansl=max(get(1, dwn), get(dwn, n)), ansr=max(get(1, up), get(up, n));
	if (ansl<=ansr){
		cycle+=dwn;
		cout<<ansl+1<<' '<<(cycle+2*n)%n<<'\n';
		return 0;
	}
	cycle+=up;
	cout<<ansr+1<<' '<<(cycle+2*n)%n<<'\n';
		
	return 0;
}