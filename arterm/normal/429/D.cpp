#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define M 100100
#define long long long

long n, ans;

struct point{
    long x, y;
} a[M];

inline long sq(long x){
    return x*x;
}

void read(void){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].y, a[i].y += a[i - 1].y;
        a[i].x = i;
    }
    ans = sq(a[1].y - a[2].y) + 1;
}

void upd(const point &x, const point &y){
    long t = sq(x.x - y.x) + sq(x.y - y.y);
    if (ans > t)
        ans = t;
}

bool cmp(const point &x, const point &y){
    return x.y < y.y || (x.y==y.y && x.x<y.x);
}

void rec(int l, int r){
    if (r - l <= 3){
        for (int i = l; i < r; ++i)
        for (int j = i + 1; j < r; ++j)
            upd(a[i], a[j]);
        sort(a + l, a + r, cmp);
        return;
    }

    int m = (l + r) / 2;

    rec(l, m);
    rec(m, r);

    long mid = a[m-1].x;

    static point t[M];

    merge(a + l, a + m, a + m, a + r, t + l, cmp);
    for (int i = l; i < r; ++i)
        a[i] = t[i];

    int ts = 0;

    for (int i = l; i < r; ++i)
    if (sq(mid - a[i].x) < ans){
        for (int j = ts - 1; j >= 0 && sq(a[i].y - t[j].y) < ans; --j)
            upd(a[i], t[j]);
        t[ts++] = a[i];
    }
}

int main(){
#ifdef GORILLA
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    read();
    rec(1, n + 1);
    cout << ans << "\n";
    
    return 0;
}