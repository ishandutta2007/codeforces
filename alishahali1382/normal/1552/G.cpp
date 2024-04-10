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
#define get(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int N=41;

int n, m, k, u, v, x, y, t, a, b, ans;
int ted[11];
ll Q[11];
vector<int> vec[11];
ll tof[11][N+1];

void SIK(){
	cout<<"REJECTED\n";
	exit(0);
}

void BT(int i, ll mask0, ll mask1){
//	debug(i)
//	debug2(mask0, mask1)
	if (i==k){
//		debug("shit")
		if (__builtin_popcountll(mask0|mask1)<n) SIK();
//		debug("not first")
		if (mask1 && mask0 && __builtin_ctzll(mask1)!=__builtin_popcountll(mask0)) SIK();
//		debug("ok")
		return ;
	}
	int c0=__builtin_popcountll(Q[i]&mask0);
	int c1=__builtin_popcountll(Q[i]&mask1);
	int sz=ted[i]-c0-c1;
	for (int j=0; j<n; j++) if (get(Q[i], j)){
		mask0&=~(1ll<<j);
		mask1&=~(1ll<<j);
	}
	for (int j=0; j<=sz; j++){
		BT(i+1, mask0|tof[i][j+c0], mask1^Q[i]^tof[i][j+c0]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	if (n==1) kill("ACCEPTED")
	ll shit=0;
	for (int i=0; i<k; i++){
		cin>>ted[i];
		for (int j=0; j<ted[i]; j++){
			cin>>x;
			x--;
			vec[i].pb(x);
			Q[i]|=(1ll<<x);
			tof[i][j+1]=tof[i][j]|(1ll<<x);
		}
		shit|=Q[i];		
	}
	if (shit!=(1ll<<n)-1) SIK();
	BT(0, 0, 0);
	kill("ACCEPTED")
	
	return 0;
}
/*
5 1
5 1 2 3 4 5

2 2
2 1 2
2 1 2

*/