#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e5 + 1;
const ld EPS = 1e-9;
const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;

struct pt {
    int x, y;
    pt() {}
    pt(int x, int y): x(x), y(y) {}
};

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int a[N];
int cnt[N], ans[N];

int main() {
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    set <pair <int, int> > s;

    fr(i, n) {
        cin >> a[i];
        a[i]--;
    }

    fr(l, n) {
        int mx = 0, mx2 = 0;
        fill(cnt, cnt + n, 0);
        frab(r, l, n) {
            cnt[a[r]]++;
            if (cnt[a[r]] > mx || cnt[a[r]] == mx && a[r] < mx2)
                mx = cnt[a[r]], mx2 = a[r];
            ans[mx2]++;
        }
    }
    fr(i, n)
        cout << ans[i] << " ";
}