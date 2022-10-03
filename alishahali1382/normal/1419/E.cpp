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
const int MAXN=300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
vector<int> P, D;

void makeD(int n){
	D.clear();
	for (int i=1; i*i<=n; i++) if (n%i==0){
		if (i!=1) D.pb(i);
		if (i!=n/i) D.pb(n/i);
	}
}

void Solve(){
	P.clear();
	cin>>n;
	int tmp=n;
	for (int i=2; i*i<=tmp; i++) if (tmp%i==0){
		while (tmp%i==0) tmp/=i;
		P.pb(i);
	}
	if (tmp>1) P.pb(tmp);
	if (P.size()==1){
		for (int x=n; x>1; x/=P[0]) cout<<x<<" ";
		cout<<"\n0\n";
		return ;
	}
	for (int p:P) if ((n/p)%p==0){
		int t=0;
		while (n%p==0) n/=p, t++;
		makeD(n);
		
		for (int x=p, i=1; i<=t; i++, x*=p) cout<<x<<" ";
		for (int d:D){
			cout<<d*p<<" "<<d<<" ";
			d*=p*p;
			for (int i=2; i<=t; i++, d*=p) cout<<d<<" ";
		}
		cout<<"\n0\n";
		return ;
	}
	if (P.size()==2){
		cout<<P[0]<<" "<<P[1]<<" "<<n<<"\n1\n";
		return ;
	}
	int p1=P.back(); P.pop_back();
	int p2=P.back(); P.pop_back();
	int p3=P.back(); P.pop_back();
	vector<int> vec={p1, p1*p2*p3, p1*p2, p2, p2*p3, p3, p1*p3};
	
	for (int i:vec) cout<<i<<" ";
	int sz=P.size();
	for (int mask=1; mask<(1<<sz); mask++){
		int x=1;
		for (int i=0; i<sz; i++) if (mask&(1<<i)) x*=P[i];
		cout<<vec[0]*x<<" "<<x<<" ";
		for (int i=1; i<=6; i++) cout<<vec[i]*x<<" ";
	}
	cout<<"\n0\n";
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;cin>>T;
	while (T--) Solve();
	
	return 0;
}