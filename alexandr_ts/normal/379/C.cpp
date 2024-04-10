#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef unsigned long long ll;

const int N = 1e6 + 10;
const int INF = 2e9;
const int ALPH = 300;

struct tmp {
    int x, pos;
} a[N];

bool cmp1(tmp a, tmp b) {
    return a.x < b.x;
}

bool cmp2(tmp a, tmp b) {
    return a.pos < b.pos;
}



int main() {
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    frab(i, 0, n) {
        cin >> a[i].x;
        a[i].pos = i;
    }
    sort(a, a + n, cmp1);
    int ans = 0;
    frab(i, 1, n)
        if (a[i].x <= a[i - 1].x)
            ans += a[i].x - a[i].x + 1, a[i].x = a[i - 1].x + 1;
    sort(a, a + n, cmp2);
    fr(i, n)
        cout << a[i].x << " ";

}