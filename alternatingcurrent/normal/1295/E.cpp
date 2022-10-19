#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
ll qmin(ll a, ll b){
	return (a < b) ? a : b;
}

int n;
int p[200200];
ll a[200200];
ll cost_num[200200];

ll cost_here[200200];
int n_sgt;
ll dat[800800];
ll laz[800800];

void build_tree(){
	n_sgt = 1;
	while(n_sgt <= n) n_sgt <<= 1;
	memset(dat, 0, sizeof(dat));
	memset(laz, 0, sizeof(laz));
}

void update(ll x, ll target_l, ll target_r, int pos, int now_l, int now_r){
	if(now_r < target_l || now_l > target_r) return ;
	if(target_l <= now_l && target_r >= now_r){
		laz[pos] += x;
		return ;
	}
	int mid = (now_l + now_r) >> 1;
	update(x, target_l, target_r, pos*2, now_l, mid);
	update(x, target_l, target_r, pos*2+1, mid+1, now_r);
	dat[pos] = qmin(dat[pos*2] + laz[pos*2], dat[pos*2+1] + laz[pos*2+1]);
	return ;
}

int main(){
	scanf("%d", &n);
	rep(i, n) scanf("%d", &p[i]);
	rep(i, n) scanf("%lld", &a[i]);
	rep(i, n) cost_num[p[i]-1] = a[i];
	cost_here[0] = 0;
	for(int i = 1; i <= n; i++){
		cost_here[i] = cost_here[i-1] + cost_num[i-1];
	}
	build_tree();
	for(int i = 0; i <= n; i++){
		update(cost_here[i], i, i, 1, 0, n);
	}
	ll ans = cost_here[n];
	for(int k = 0; k < n-1; k++){
		update(-a[k], p[k], n, 1, 0, n);
		update(a[k], 0, p[k]-1, 1, 0, n);
		ans = qmin(ans, dat[1]+laz[1]);
	}
	cout << ans << endl;
	return 0;
}