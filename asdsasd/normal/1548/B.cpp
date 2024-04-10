#include<bits/stdc++.h>
using namespace std;

struct SegTree{
	private:
		int n;
		vector<long long> node;
 
	public:
		SegTree(int sz){
			n = 1;
			while(n < sz) n *= 2;
			node.resize(2 * n - 1, 0);
			for(int i = n - 2; i >= 0; i--) node[i] = gcd(node[2 * i + 1], node[2 * i + 2]);
		}
 
		void update(int x, long long val){
			x += n - 1;
			node[x] = val;
			while(x > 0){
				x = (x - 1) / 2;
				node[x] = gcd(node[2 * x + 1], node[2 * x + 2]);
			}
		}
 
		long long getgcd(int a, int b, int k = 0, int l = 0, int r = -1){
			if(r < 0) r = n;
			if(r <= a || b <= l) return 0;
			if(a <=l && r <= b) return node[k];
 
			long long vl = getgcd(a, b, 2 * k + 1, l, (l + r) / 2);
			long long vr = getgcd(a, b, 2 * k + 2, (l + r) / 2, r);
			return gcd(vl, vr);
		}
 
		long long get(int i){
			return node[i + n - 1];
		}
};

void solve(){
    int n;
    scanf("%d", &n);
    vector<long long> A(n);
    for(int i = 0; i < n; i++) scanf("%llu", &A[i]);
    vector<long long> d(n - 1);
    for(int i = 0; i < n - 1; i++) d[i] = A[i + 1] - A[i];
    int ans = 1;
    n--;
    SegTree seg(n);
    for(int i = 0; i < n; i++){
        seg.update(i, d[i]);
    }
    for(int i = 0; i < n; i++){
        int l = i;
        int r = n + 1;
        while(r - l > 1){
            int mid = (r + l) / 2;
            if(abs(seg.getgcd(i, mid)) == 1) r = mid;
            else l = mid;
        }
        ans = max(ans, l - i + 1);
    }
    printf("%d\n", ans);
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--) solve();
	return 0;
}