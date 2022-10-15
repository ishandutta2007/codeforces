#include <queue>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
#define FOREACH(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

const int MAXN = 1000007 * 4;
const int ROOT = 1;

int opn[MAXN], cls[MAXN];
string s;
int n, m;

void build_tree(int i, int l, int r)
{
    if (l == r) {
        opn[i] = s[l] == '(';
        cls[i] = s[l] == ')';
    } else {
        int c = (l + r) / 2;
        int lchild = (i << 1) + 0;
        int rchild = (i << 1) + 1;
        build_tree(lchild, l, c);
        build_tree(rchild, c + 1, r);

        cls[i] = cls[lchild] + max(cls[rchild] - opn[lchild], 0);
        opn[i] = opn[rchild] + max(opn[lchild] - cls[rchild], 0);
    }
    //cout << "bd: " << i << " " << l << " " << r << " " << cls[i] << " " << opn[i] << endl;
}

void get_open(int i, int l, int r, const int L, const int R, int &open, int &ans)
{
    //cout << i << " " << l << " " << r << " " << L << " " << R << " " << open << " " << ans << endl;
    if (L <= l && r <= R) {
        //cout << "go: " << i << " " << l << " " << r << " " << cls[i] << " " << opn[i] << endl;
        ans -= max(cls[i] - open, 0);
        open = max(open - cls[i], 0) + opn[i];
        return;
    }
    
    int c = (l + r) / 2;
    if (L <= c)
        get_open((i << 1) + 0, l, c, L, R, open, ans);
    if (c < R)
        get_open((i << 1) + 1, c + 1, r, L, R, open, ans);
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
    cin >> s;
    n = s.size();
    build_tree(ROOT, 0, n - 1);

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        int open = 0;
        int ans = r - l + 1;
        get_open(ROOT, 0, n - 1, l, r, open, ans);
        ans -= open;
        cout << ans << "\n";
    }
	return 0;
}