#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (register int i = a, end = b; i <= end; i++)
#define repd(i, a, b) for (register int i = a, end = b; i >= end; i--)
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define INF (1<<30)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define fst first
#define snd second
#define pii pair<int, int>

inline int read() {
    int w = 0, f = 1; char c;
    while (!isdigit(c = getchar())) f = c == '-' ? -1 : f;
    while (isdigit(c)) w = (w << 3) + (w << 1) + (c ^ 48), c = getchar();
    return w * f;
}

const int maxn = 200000 + 5;

int N, K, b, c;
int a[maxn];
struct Node {
    int h;
    ll w;
    bool operator < (const Node &rhs) const {
        return w+(100ll*INF-h)*b < rhs.w + (100ll*INF-rhs.h)*b;
    }
};
priority_queue<Node> q;
ll ans = 1ll<<60;

int main() {
    N = read(), K = read(), b = read(), c = read();
    b = min(b, 5*c);
    rep(i, 1, N) a[i] = read() + 1000000000;
    sort(a+1, a+N+1);
    rep(mod, 0, 4) {
    	ll _ans = 0, up = 0, _up;
    	while (!q.empty()) q.pop();
        for (register int i = 1; i <= N; ++i) {
            _up = up; up = a[i]%5 ^ mod ? a[i]+5-(a[i]+5-mod)%5: a[i];
        	_ans += (up - _up) / 5 * q.size() * b;
            ll val = c*(up-a[i]);
            q.push((Node){(up-mod)/5, val});
            _ans += val;
            while (up == (_up = a[i]%5 ^ mod ? a[i+1]+5-(a[i+1]+5-mod)%5 : a[i+1])) {
            	q.push((Node){(_up-mod)/5, val = c*(_up-a[++i])});
            	_ans += val;
			}
            while ((int)q.size() > K) {
            	Node u = q.top(); q.pop();
            	_ans -= u.w + ((up-mod)/5 - u.h) * b;
			}
			if ((int)q.size() == K) chkmin(ans, _ans);
        }
    }
    printf("%lld", ans);
    return 0;
}