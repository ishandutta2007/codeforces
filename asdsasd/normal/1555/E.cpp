#include<bits/stdc++.h>
using namespace std;
int inf = 1 << 30;

struct LazySegTree{
	private:
		int n;
		vector<int> node, lazy;

	public:
		LazySegTree(int sz){
			n = 1;
			while (n < sz) n *= 2;
			node.resize(2 * n - 1, 0);
			lazy.resize(2 * n - 1, 0);
		}

		void eval(int k, int l, int r){
			if(lazy[k] != 0){
				node[k] += lazy[k];

				if(r - l > 1){
					lazy[2 * k + 1] += lazy[k];
					lazy[2 * k + 2] += lazy[k];
				}
				lazy[k] = 0;
			}
		}

		void add(int a, int b, int x, int k = 0, int l = 0, int r = -1){
			if(r < 0) r = n;
			eval(k, l, r);
			if(b <= l || r <= a) return;
			if(a <= l && r <= b){
				lazy[k] += x;
				eval(k, l, r);
			}
			else{
				add(a, b, x, 2 * k + 1, l, (l + r) / 2);
				add(a, b, x, 2 * k + 2, (l + r) / 2, r);
				node[k] = min(node[2 * k + 1], node[2 * k + 2]);
			}
		}

		int getmin(int a, int b, int k = 0, int l = 0, int r = -1){
			if(r < 0) r = n;
			if(b <= l || r <= a) return inf;

			eval(k, l, r);
			if(a <= l && r <= b) return node[k];
			int vl = getmin(a, b, 2 * k + 1, l, (l + r) / 2);
			int vr = getmin(a, b, 2 * k + 2, (l + r) / 2, r);
			return min(vl, vr);
		}
};

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int>> wlr(n, vector<int>(3));
	for(int i = 0; i < n; i++) scanf("%d %d %d", &wlr[i][1], &wlr[i][2], &wlr[i][0]);
	LazySegTree seg(m);
	sort(wlr.begin(), wlr.end());
	int lp = 0, rp = 0;
	wlr.push_back({0, 1, inf});
	while(seg.getmin(1, m) == 0){
	    seg.add(wlr[rp][1], wlr[rp][2], 1);
	    rp++;
	}
	while(seg.getmin(1, m) > 0){
	    seg.add(wlr[lp][1], wlr[lp][2], -1);
	    lp++;
	}
	int bw = wlr[rp][0];
	int ans = wlr[rp - 1][0] - wlr[lp - 1][0];
	while(rp < n){
	    while(wlr[rp][0] == bw){
	        seg.add(wlr[rp][1], wlr[rp][2], 1);
	        rp++;
	    }
	    while(seg.getmin(1, m) > 0){
    	    seg.add(wlr[lp][1], wlr[lp][2], -1);
    	    lp++;
	    }
	    ans = min(ans, wlr[rp - 1][0] - wlr[lp - 1][0]);
	    bw = wlr[rp][0];
	}
	printf("%d\n", ans);
	return 0;
}