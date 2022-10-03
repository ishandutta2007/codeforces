#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
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
const int MAXN = 200010, LOG=20;

struct node{
	int l, r;
} A[MAXN];

int n, m, k, u, v, x, y, team=1, a, b;
int ans[MAXN];
int pos[MAXN];
vector<int> vec;
set<pii> st;

void rem(int ind){
	A[A[ind].l].r=A[ind].r;
	A[A[ind].r].l=A[ind].l;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++){
		cin>>x;
		A[i].l=i-1;
		A[i].r=i+1;
		pos[x]=i;
	}
	A[n+1].r=n+1;
	A[n+1].l=n;
	A[0].r=1;
	for (int num=n; num; num--){
		int ind=pos[num];
		if (ans[ind]) continue ;
		for (int i=1, x=A[ind].l; i<=k && x!=A[x].l; i++, x=A[x].l) vec.pb(x);
		for (int i=1, x=A[ind].r; i<=k && x!=A[x].r; i++, x=A[x].r) vec.pb(x);
		vec.pb(ind);
		for (int i:vec) rem(i), ans[i]=team;
		vec.clear();
		team=3-team;
	}
	for (int i=1; i<=n; i++) cout<<ans[i];
	
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