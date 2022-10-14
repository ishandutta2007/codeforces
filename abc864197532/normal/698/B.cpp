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
#define X first
#define Y second
struct Dsu {
	int n;
	vector <int> dsu, size;
	Dsu (int _n): n(_n) {
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
		if (size[x] < size[y]) {
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
    Dsu dsu(n);
    vector <int> ans(n);
    int k = 0;
    int rt = -1;
    fop (i,0,n) {
        cin >> a[i];
        a[i]--;
        ans[i] = a[i];
        if (a[i] == i) {
            if (rt == -1) rt = i;
            else {
                k++;
                ans[i] = rt;
                dsu.Union(rt, i);
            }
        } else {
            if (!dsu.Union(a[i], i)) {
                if (rt == -1) ans[i] = -1, k++;
                else {
                    ans[i] = rt;
                    k++;
                    dsu.Union(rt, i);
                }
            }
        }
    }
    if (rt == -1) {
        fop (i,0,n) if (ans[i] == -1) rt = i;
    }
    fop (i,0,n) if (ans[i] == -1) ans[i] = rt;
    cout << k << endl;
    for (int i : ans) cout << i + 1 << ' ';
}