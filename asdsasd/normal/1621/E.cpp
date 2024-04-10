#include<bits/stdc++.h>
using namespace std;

struct LazySegTree{
	private:
		int n;
		vector<int> node, lazy;

	public:
		LazySegTree(int sz){
			n = 1;
			while (n< sz) n *= 2;
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
			if(b <= l || r <= a) return 0;

			eval(k, l, r);
			if(a <= l && r <= b) return node[k];
			int vl = getmin(a, b, 2 * k + 1, l, (l + r) / 2);
			int vr = getmin(a, b, 2 * k + 2, (l + r) / 2, r);
			return min(vl, vr);
		}
};

void solve(){
    int n, m;
    cin >> n >> m;
    vector<long long> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    sort(A.begin(), A.end());
    for(int i = 0; i < m; i++) A[i] = A[i + n - m];
    A.resize(m);
    vector<vector<long long>> B(m, vector<long long>());
    vector<long long> K(m);
    vector<long long> S(m, 0);
    vector<int> bp(m);
    vector<int> imos(m + 1, 0);
    for(int i = 0; i < m; i++){
        cin >> K[i];
        B[i].resize(K[i]);
        for(int j = 0; j < K[i]; j++){
            cin >> B[i][j];
            S[i] += B[i][j];
        }
        long long x = (S[i] + K[i] - 1) / K[i];
        auto it = lower_bound(A.begin(), A.end(), x);
        bp[i] = (it - A.begin());
        imos[bp[i]]++;
    }
    for(int i = 1; i < m; i++) imos[i] += imos[i - 1];
    for(int i = 0; i < m; i++) imos[i] -= i + 1;
    LazySegTree seg(m);
    for(int i = 0; i < m; i++){
        seg.add(i, i + 1, imos[i]);
    }
    for(int i = 0; i < m; i++){
        seg.add(bp[i], m + 1, -1);
        for(auto b: B[i]){
            long long ss = S[i] - b;
            long long kk = K[i] - 1;
            long long x = (ss + kk - 1) / kk;
            auto it = lower_bound(A.begin(), A.end(), x);
            int p = (it - A.begin());
            seg.add(p, m + 1, 1);
            if(seg.getmin(0, m) >= 0) cout << 1;
            else cout << 0;
            seg.add(p, m + 1, -1);
        }
        seg.add(bp[i], m + 1, 1);
    }
    
    cout << "\n";
}

int main(){
	int t;
	cin >> t;
	while(t--) solve();
	
	
	return 0;
}