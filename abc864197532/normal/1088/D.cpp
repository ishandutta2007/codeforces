#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, y = 111222333, N = 3000;

int ask (int a, int b) {
	cout << "? " << a << ' ' << b << endl;
	cin >> a;
        return a;
}

int main () {
	int l = ask(0, 0);
	int A = 0, B = 0;
	FOP (i,30,0) {
		int tmp = ask(A + (1 << i), B + (1 << i));
		if (l == 0 or tmp != -l) {
			tmp = ask(A + (1 << i), B);
                        if (tmp == -1) {
		        	A += (1 << i);
		         	B += (1 << i);
		        }
		} else {
			(l == 1 ? A : B) += (1 << i);
			l = ask(A, B);
		}
	}
	cout << "! " << A << ' ' << B << endl;
	exit(0);
}