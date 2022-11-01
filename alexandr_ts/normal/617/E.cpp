#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<ll> > mat;

const int N = 1e5 + 10;
const int M = (1 << 20) + 1;
const int BLOCK = sqrt(N);

struct Seg {
    int l;
    int r;
    int num;
    ll ans;
} seg[N];

bool cmp(const Seg& a, const Seg& b) {
    int ablock = a.l / BLOCK;
    int bblock = b.l / BLOCK;
    if (ablock != bblock)
        return ablock < bblock;
    return a.r < b.r;
}

bool cmpNum(const Seg& a, const Seg& b) {
    return a.num < b.num;
}

int a[N];
int pref[N];

ll curans = 0;
int l = 1, r = 1;
ll cnt[M];
int k;

void toSeg(int tl, int tr) {
    int newl = min(l, tl);
    int newr = max(r, tr);
    for (int i = l - 1; i >= newl; i--) {
        curans += cnt[k ^ pref[i - 1]];
        cnt[pref[i - 1]]++;
    }
    for (int i = r + 1; i <= newr; i++) {
        curans += cnt[k ^ pref[i]];
        cnt[pref[i]]++;
    }
    for (int i = newl; i < tl; i++) {
        cnt[pref[i - 1]]--;
        curans -= cnt[k ^ pref[i - 1]];
    }
    for (int i = newr; i > tr; i--) {
        cnt[pref[i]]--;
        curans -= cnt[k ^ pref[i]];
    }

    l = tl, r = tr;
}

void solve() {
    int n, m;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++) {
        cin >> seg[i].l >> seg[i].r;
        seg[i].num = i;
    }

    pref[0] = 0;
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] ^ a[i - 1];

    sort(seg, seg + m, cmp);

    cnt[0] = 1;
    cnt[pref[1]]++;
    if (pref[1] == k) curans++;


    for (int i = 0; i < m; i++) {
        toSeg(seg[i].l, seg[i].r);
        seg[i].ans = curans;
    }

    sort(seg, seg + m, cmpNum);

    for (int i = 0; i < m; i++)
        cout << seg[i].ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);

    solve();

}