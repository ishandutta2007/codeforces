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
#include <set>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
#define FOREACH(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)

const int MAXN = 1000007;
const int INF = (int)1e+9 + 7;

int s[MAXN];
int n, m;
int a[MAXN], b[MAXN];
int p[MAXN];
int q[MAXN];
int l[MAXN], r[MAXN];

int f[MAXN];

void modify(int x)
{
    for (int i = x; i <= n; i += i & -i) {
        s[i] += 1;
    }
}

int findsum(int x)
{
    int r = 0;
    for (int i = x; 1 <= i; i -= i & -i) {
        r += s[i];
    }
    return r;
}


void modifymin(int x, int v)
{
    for (int i = x; i <= n; i += i & -i) {
        f[i] = min(f[i], v);
    }
}

int findmin(int x)
{
    int r = INF;
    for (int i = x; 1 <= i; i -= i & -i) {
        r = min(r, f[i]);
    }
    return r;
}

void modifymax(int x, int v)
{
    for (int i = x; i <= n; i += i & -i) {
        f[i] = max(f[i], v);
    }
}

int findmax(int x)
{
    int r = 0;
    for (int i = x; 1 <= i; i -= i & -i) {
        r = max(r, f[i]);
    }
    return r;
}

int findsum(int l, int r)
{
    return findsum(r) - findsum(l - 1);
}


int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[a[i]] = i;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
        q[b[i]] = i;
    }
    
    for (int i = 1; i <= n; ++i) {
        f[i] = 0;
    }
    
    for (int i = 1; i <= n; ++i) {
        if (q[a[i]]) {
            modifymax(a[i], i);
            continue;
        }
        int x = findmax(a[i]);
        l[i] = x;
    }
    
    for (int i = 1; i <= n; ++i) {
        f[i] = n + 1;
    }
    for (int i = n; i >= 1; --i) {
        if (q[a[i]]) {
            modifymin(a[i], i);
            continue;
        }
        int x = findmin(a[i]);
        r[i] = x;
    }
    
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        int x = p[i];
        if (q[i]) {
            continue;
        }
        //cout << l[x] << " " << r[x] << endl;
        ans += r[x] - l[x] - 1 - findsum(l[x] + 1, r[x] - 1);
        modify(x);
    }
    cout << ans << endl;
	return 0;
}