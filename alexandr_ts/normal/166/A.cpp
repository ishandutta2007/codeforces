#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ld;
typedef long long ll;

const int N = 1e6;
const ld EPS = 1e-8;
const ld INF = 1e15;

struct tmp {
    int x, y;
} a[N];

bool cmp(tmp a, tmp b) {
    return a.x > b.x || a.x == b.x && a.y < b.y;
}

int main() {
    ld st = clock();
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    fr(i, n) {
        cin >> a[i].x >> a[i].y;
    }
    sort(a, a + n, cmp);
    int ans = 0;
    fr(i, n)
        if (!cmp(a[i], a[k - 1]) && !cmp(a[k - 1], a[i]))
            ans++;
    cout << ans;
}