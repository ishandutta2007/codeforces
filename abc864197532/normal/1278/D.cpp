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
int dsu[1000010];

int find (int n) {
    if (dsu[n] == n) return n;
    return dsu[n] = find(dsu[n]);
}

bool Union (int a, int b) {
    int x = find(a), y = find(b);
    if (x == y) return false;
    if (x > y) swap(x,y);
    dsu[x] = y;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
	int n,a,b;
	cin >> n;
	vector <pii> input;
	fop (i,0,n) {
		cin >> a >> b;
		input.eb(a,b);
	}
	sort(input.begin(), input.end());
	set <int> nums;
	int edge = 0;
    fop (i,0,1000010) dsu[i] = i;
    fop (i,0,n) {
		tie(a,b) = input[i];
		if (!nums.size()) {
			nums.insert(b);
		} else {
            auto aa = nums.lower_bound(a), bb = nums.lower_bound(b);
            for (auto it = aa; it != bb; it++) {
                if (!Union(*it, b)) {
                    cout << "NO" << endl;
                    return 0;
			    }
			    edge++;
    			if (edge >= n) {
                    cout << "NO" << endl;
                    return 0;
    			}
            }
			nums.insert(b);
		}
	}
	if (edge == n - 1) cout << "YES" << endl;
	else cout << "NO" << endl;
}