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
const int N=105;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[N][N];
vector<pii> v1, v2;

int get(){
	int x;
	cin>>x;
	return x;
}
void put(int b, int i, int j){
	cout<<b<<" "<<i<<" "<<j<<endl;
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++){
		if ((i+j)&1) v1.pb({i, j});
		else v2.pb({i, j});
	}
	for (int i=0; i<n*n; i++){
		int col=get();
		if (v1.size() && col!=1){
			pii p=v1.back();
			v1.pop_back();
			put(1, p.first, p.second);
			continue ;
		}
		if (v2.size() && col!=2){
			pii p=v2.back();
			v2.pop_back();
			put(2, p.first, p.second);
			continue ;
		}
		if (v1.size()){
			pii p=v1.back();
			v1.pop_back();
			put(3, p.first, p.second);
			continue ;
		}
		if (v2.size()){
			pii p=v2.back();
			v2.pop_back();
			put(3, p.first, p.second);
			continue ;
		}
		cout<<1/0;
	}
	
	
	return 0;
}