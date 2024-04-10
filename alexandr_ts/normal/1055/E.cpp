#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef unsigned long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int MAX = 1e9 + 1;
const int N = 2e3 + 10;

int a[N], c[N];
pair <int, int> seg[N];

int minl[N];
int d[N][N];
int pref[N];

int solveOK(int n, int s, int m, int k) {
    int tl = -1, tr = *max_element(a, a + n) + 20;
    while (tr - tl > 1) {
        int tm = (tl + tr) / 2;
        fr(i, n) {
            c[i] = (a[i] <= tm);
            pref[i + 1] = pref[i] + c[i];
        }
//        cout << tm << "  ";
//        fr(i, n)
//            cout << c[i] << " ";cout << endl;
        fr(i, n)
            fr(j, s + 1)
                d[i][j] = 0;
        frab(j, 1, m + 1)
            fr(i, n) {
                d[i][j] = d[i][j - 1];
                if (i)
                    d[i][j] = max(d[i][j], d[i - 1][j]);
                if (minl[i] != INF) {
                    int l = minl[i];
                    d[i][j] = max(d[i][j], (l ? d[l - 1][j - 1] : 0) + pref[i + 1] - pref[l]);
                }
            }
        if (d[n - 1][m] >= k)
            tr = tm;
        else
            tl = tm;
    }

    if (tr == *max_element(a, a + n) + 20)
        return -1;
    else
        return tr;
}

int solveTL(int n, int s, int m, int k) {
    int ans = INF;
    for (int mask = 0; mask < (1 << s); mask++) {
        vector<int> used(n, false);
        fr(i, s)
            if ((1 << i) & mask)
                frab(j, seg[i].first, seg[i].second + 1)
                    used[j] = true;
        vector<int> nums;
        fr(i, n)
            if (used[i])
                nums.pb(a[i]);
        sort(nums.begin(), nums.end());
        if (nums.size() >= k)
            ans = min(ans, nums[k - 1]);
    }
    if (ans == INF)
        return -1;
    return ans;
}

int main() {
    //freopen("a.in", "r", stdin);

    int n, s, m, k;
    cin >> n >> s >> m >> k;
    fr(i, n)
        cin >> a[i];
    fr(i, n)
        minl[i] = INF;
    fr(i, s) {
        cin >> seg[i].first >> seg[i].second;
        --seg[i].first;
        --seg[i].second;
        minl[seg[i].second] = min(minl[seg[i].second], seg[i].first);
        for (int i = n - 2; i >= 0; i--)
            minl[i] = min(minl[i], minl[i + 1]);
    }

    cout << solveOK(n, s, m, k) << " ";
    //cout << solveTL(n, s, m, k) << endl;


//    int n, s, m, k;
//    while (true) {
//        n = rand() % 3 + 1;
//        k = rand() % n + 1;
//        fr(i, n) {
//            a[i] = rand() % 6 + 1;
//            minl[i] = INF;
//        }
//        m = rand() % 3 + 1;
//        s = rand() % 3 + m;
//        fr(i, s) {
//            seg[i].first = rand() % n;
//            seg[i].second = rand() % n;
//            if (seg[i].first > seg[i].second)
//                swap(seg[i].first, seg[i].second);
//            minl[seg[i].second] = min(minl[seg[i].second], seg[i].first);
//        }
//        int ansOK = solveOK(n, s, m, k);
//        int ansTL = solveTL(n, s, m, k);
//        if (ansOK != ansTL) {
//            cout << ansOK << " " << ansTL << endl;
//            cout << n << " " << s << " " << m << " " << k << endl;
//            fr(i, n) cout << a[i] << " ";cout << endl;
//            fr(i, s)
//                cout << seg[i].first + 1 << " " << seg[i].second + 1 << endl;
//            break;
//        }
//    }
}