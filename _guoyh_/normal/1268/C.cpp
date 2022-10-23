# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 200051;
struct BIT{
	ll c[MAXN];
	int lowbit(int x){
		return x & (-x);
	}
	void modify(int pos, ll nm){
		for (int i = pos; i < MAXN; i += lowbit(i)) c[i] += nm;
	}
	ll getsum(int pos){
		ll ans = 0;
		for (int i = pos; i; i -= lowbit(i)) ans += c[i];
		return ans;
	}
	int getmid(ll val){
		ll nm = 0;
		int nw = 0;
		for (int i = 20; i >= 0; i--){
			if (nw + (1 << i) >= MAXN) continue;
			if (c[nw + (1 << i)] + nm < val){
				nm += c[nw + (1 << i)];
				nw += 1 << i;
			}
		}
		return nw + 1;
	}
} t1, t2;
int n;
int a[MAXN];
int pos[MAXN];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", a + i);
		pos[a[i]] = i;
	}
	ll ans2 = 0;
	for (int i = 1; i <= n; i++){
		t1.modify(pos[i], 1);
		t2.modify(pos[i], pos[i]);
		ans2 += t1.getsum(n) - t1.getsum(pos[i]);
		int hf = (i + 1) / 2;
		int pm = t1.getmid(hf);
//		printf("%d %d %d\n", i, hf, pm);
		ll ans1 = 1ll * (pm + pm - hf + 1) * hf / 2 - t2.getsum(pm);
		ans1 += t2.getsum(n) - t2.getsum(pm) - 1ll * (pm + 1 + pm + i - hf) * (i - hf) / 2;
		printf("%lld ", ans1 + ans2);
	}
	return 0;
}