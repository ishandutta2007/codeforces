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

int n, m, k, u, v, x, y, type, l, r;
pii seg[32][MAXN*4];
int B[5];

int f(pii p){ return p.second-p.first;}

pii combine(pii x, pii y){
	return {min(x.first, y.first), max(x.second, y.second)};
}

pii update(int i, int id, int tl, int tr, int x, int val){
	if (x<tl || tr<x) return seg[i][id];
	if (tl==tr) return seg[i][id]={val, val};
	int mid=(tl+tr)>>1;
	return seg[i][id]=combine(update(i, id<<1, tl, mid, x, val), update(i, id<<1 | 1, mid+1, tr, x, val));
}

pii get(int i, int id, int tl, int tr, int l, int r){
	if (r<tl || tr<l) return {inf, -inf};
	if (l<=tl && tr<=r) return seg[i][id];
	int mid=(tl+tr)>>1;
	return combine(get(i, id<<1, tl, mid, l, r), get(i, id<<1 | 1, mid+1, tr, l, r));
}

void upd(int i){
	for(int i=0; i<k; i++) cin>>B[i];
	for (int mask=0; mask<32; mask++){
		int val=0;
		for (int j=0; j<5; j++){
			if (mask&(1<<j)) val-=B[j];
			else val+=B[j];
		}
		update(mask, 1, 1, n, i, val);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++) upd(i);
	cin>>m;
	while (m--){
		cin>>type;
		if (type==2){
			cin>>l>>r;
			int ans=0;
			for (int mask=0; mask<32; mask++) ans=max(ans, f(get(mask, 1, 1, n, l, r)));
			cout<<ans<<'\n';
		}
		else{
			cin>>x;
			upd(x);
		}
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