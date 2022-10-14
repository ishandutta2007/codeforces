#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>

struct Dsu {
	int n;
	vector <int> dsu, size;
	Dsu (int n): n(n) {
		dsu.resize(n);
		size.resize(n);
		for (int i = 0; i < n; ++i) {
			dsu[i] = i;
			size[i] = 1;
		}
	}
	int Find(int a) {
		if (dsu[a] == a) return a;
		return dsu[a] = Find(dsu[a]);
	}
	bool Union(int a, int b) {
		int x = Find(a), y = Find(b);
		if (x == y) return false;
		if (size[x] > size[y]) {
			dsu[x] = y;
			size[y] += size[x];
			size[x] = 0;
		} else {
			dsu[y] = x;
			size[x] += size[y];
			size[y] = 0;
		}
		return true;
	}
};

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	char c;
	Dsu dsu(n);
	fop (i,0,n) cin >> a[i];
	fop (i,0,n) {
	    fop (j,0,n) {
	        cin >> c;
	        if (c == '1') dsu.Union(i, j);
	    }
	}
	bool vi[n];
	fop (i,0,n) vi[i] = false;
	priority_queue<int, vector <int>, greater<int>> nums;
	fop (i,0,n) {
	    if (vi[i]) continue;
	    int k = dsu.Find(i);
	    fop (j,i,n) {
	        if (dsu.Find(j) == k) {
	            nums.push(a[j]);
	            vi[j] = true;
	        }
	    }
	    fop (j,i,n) {
	        if (dsu.Find(j) == k) {
	            a[j] = nums.top();
	            nums.pop();
	        }
	    }
	}
	fop (i,0,n) cout << a[i] << " \n"[i == n - 1];
}