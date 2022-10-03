#include <bits/stdc++.h>
#pragma GCC optimize("O2")
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
const ll INF=1000000000000001000LL;
const int mod = 1000000007;
const int MAXN = 10000010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans=INF;
ll A[MAXN];
vector<int> ind[MAXN];
vector<int> vec;
bool ok[MAXN];
bool cmp(int i, int j){ return A[i]<A[j];}

void relax(int g, int a, int b){
	ll tmp=A[a]*A[b]/g;
	if (tmp<ans){
		ans=tmp;
		x=a;
		y=b;
	}
}

void sorter(vector<int> &v){
	for (int i=v.size()-1; i>=1; i--) if (A[v[i]]<A[v[i-1]]) swap(v[i], v[i-1]);
	for (int i=v.size()-1; i>=1; i--) if (A[v[i]]<A[v[i-1]]) swap(v[i], v[i-1]);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		ind[A[i]].pb(i);
	}
	for (int i=1; i<MAXN; i++){
		sorter(ind[i]);
		if (ind[i].size()>=2) ind[i].resize(2);
	}
	for (int g=1; g<MAXN; g++){
		vec.clear();
		for (int i=g; i<MAXN; i+=g) for (int num:ind[i]) vec.pb(num);
		//sort(all(vec), cmp);
		sorter(vec);
		if (vec.size()>1){
			relax(g, vec[0], vec[1]);
		}
	}
	
	if (x>y) swap(x, y);
	cout<<x<<' '<<y<<'\n';
	
	return 0;
}
/*
      ___           ___                            ___           ___           ___           ___           ___           ___
     /\  \         /\__\      ___                 /\  \         /\__\         /\  \         /\__\         /\  \         /\__\      ___
    /::\  \       /:/  /     /\  \               /::\  \       /:/  /        /::\  \       /:/  /        /::\  \       /:/  /     /\  \
   /:/\:\  \     /:/  /      \:\  \             /:/\ \  \     /:/__/        /:/\:\  \     /:/__/        /:/\:\  \     /:/  /      \:\  \
  /::\~\:\  \   /:/  /       /::\__\           _\:\~\ \  \   /::\  \ ___   /::\~\:\  \   /::\  \ ___   /::\~\:\  \   /:/  /       /::\__\
 /:/\:\ \:\__\ /:/__/     __/:/\/__/          /\ \:\ \ \__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/__/     __/:/\/__/
 \/__\:\/:/  / \:\  \    /\/:/  /             \:\ \:\ \/__/ \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \:\  \    /\/:/  /
      \::/  /   \:\  \   \::/__/               \:\ \:\__\        \::/  /       \::/  /       \::/  /       \::/  /   \:\  \   \::/__/
      /:/  /     \:\  \   \:\__\                \:\/:/  /        /:/  /        /:/  /        /:/  /        /:/  /     \:\  \   \:\__\
     /:/  /       \:\__\   \/__/                 \::/  /        /:/  /        /:/  /        /:/  /        /:/  /       \:\__\   \/__/
     \/__/         \/__/                          \/__/         \/__/         \/__/         \/__/         \/__/         \/__/
*/