#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define M 200100
#define T 507
#define long long long 

int n, d, a[M], b[M], c[M], p[M], t[M], ans[M];
long x;
int cnt = 0;

void read() {
    cin >> n >> d >> x;
}

long getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}

void initAB() {
    for(int i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(int i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

void find(int x) {
    int pos = p[x];
    for (int i = 0; i < d && t[i] + pos < n; ++i)
        if (ans[t[i] + pos] == 0) {
            ++cnt;
            ans[t[i] + pos] = x;
        }

}

void rem(int x) {
    for (int i = 0; i < d && t[i] <= x; ++i)
        ans[x] = max(ans[x], a[x - t[i]]);
}

void kill() {
    for (int i = 0; i < n; ++i)
        p[a[i]] = i;

    int m = 0;
    for (int i = 0; i < n; ++i)
        if (b[i])
            t[m++] = i;

    if (d < T) {
        for (int i = n; i >= 1; --i)
            find(i);
    }
    else {
        for (int i = n; i >= n - T && i>= 1; --i)
            find(i);
        for (int i = t[0]; i <= n; ++i)
            if (ans[i] == 0)
                rem(i);
    }

    for (int i = 0; i < n; ++i, cout << "\n")
        cout << ans[i];

}

int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    read();
    initAB();
    kill();

    return 0;
}