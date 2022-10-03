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
const int N=21, MAXN=1<<N;
typedef complex<double> cd;
const double PI=acos(-1);

int n, m, k, u, v, x, y, t, a, b, ans;
int rev[MAXN], mark[MAXN];
cd A[MAXN];

void FFT(cd *A, int inv){
	int n=(1<<N);
	for (int i=1; i<n; i++) if (rev[i]<i) swap(A[rev[i]], A[i]);
	for (int ln=1; ln<n; ln<<=1){
		double theta=PI/ln*inv;
		cd wn(cos(theta), sin(theta));
		for (int i=0; i<n; i+=2*ln){
			cd wnk=1;
			for (int j=i; j<i+ln; j++){
				cd x=A[j], y=A[j+ln]*wnk;
				A[j]=x+y;
				A[j+ln]=x-y;
				wnk*=wn;
			}
		}
	}
	if (inv==-1) for (int i=0; i<n; i++) A[i]/=n;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=1; i<(1<<N); i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(N-1));
	cin>>n>>m;
	while (n--){
		cin>>x;
		mark[x]=1;
		A[x]=1;
	}
	FFT(A, +1);
	for (int i=0; i<MAXN; i++) A[i]*=A[i];
	FFT(A, -1);
	vector<int> out;
	for (int i=1; i<=m; i++){
		int x=round(A[i].real());
		if (mark[i] && !x) out.pb(i);
		if (!mark[i] && x) kill("NO")
	}
	cout<<"YES\n"<<out.size()<<"\n";
	for (int i:out) cout<<i<<" ";cout<<"\n";
	
	return 0;
}
/*
6 10
5 6 7 8 9 10

*/