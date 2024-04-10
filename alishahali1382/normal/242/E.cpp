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
const int MAXN = 100010, LOG=20;

struct SEGMENT{
	struct node{
		int c0, c1;
		bool lazy;
		void rev(){
			swap(c0, c1);
			lazy^=1;
		}
	} seg[4*MAXN];
	node combine(node x, node y){
		return {x.c0+y.c0, x.c1+y.c1, 0};
	}
	node build(int id, int tl, int tr){
		if (tl==tr) return seg[id]={1, 0, 0};
		int mid=(tl+tr)>>1;
		return seg[id]=combine(build(id<<1, tl, mid), build(id<<1 | 1, mid+1, tr));
	}
	void shift(int id){
		if (!seg[id].lazy) return ;
		seg[id].lazy=0;
		seg[id<<1].rev();
		seg[id<<1 | 1].rev();
	}
	node update(int id, int tl, int tr, int l, int r){
		if (r<tl || tr<l) return seg[id];
		if (l<=tl && tr<=r){
			seg[id].rev();
			return seg[id];
		}
		shift(id);
		int mid=(tl+tr)>>1;
		return seg[id]=combine(update(id<<1, tl, mid, l, r), update(id<<1 | 1, mid+1, tr, l, r));
	}
	int get(int id, int tl, int tr, int l, int r){
		if (r<tl || tr<l) return 0;
		if (l<=tl && tr<=r) return seg[id].c1;
		shift(id);
		int mid=(tl+tr)>>1;
		return get(id<<1, tl, mid, l, r) + get(id<<1 | 1, mid+1, tr, l, r);
	}
} SEG[LOG];

int n, m, k, u, v, x, y, type, l, r, ans;
int A[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<LOG; i++) SEG[i].build(1, 1, n);
	for (int i=1; i<=n; i++){
		cin>>A[i];
		for (int j=0; j<LOG; j++) if (A[i]&(1<<j)) SEG[j].update(1, 1, n, i, i);
	}
	cin>>m;
	while (m--){
		cin>>type>>l>>r;
		if (type==2){
			cin>>x;
			for (int j=0; j<LOG; j++) if (x&(1<<j)) SEG[j].update(1, 1, n, l, r);
			continue ;
		}
		ll ans=0;
		for (int j=0; j<LOG; j++) ans+=(1ll<<j)*SEG[j].get(1, 1, n, l, r);
		cout<<ans<<'\n';
	}
	
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