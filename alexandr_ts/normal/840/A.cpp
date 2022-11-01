/// Alexandr_TS

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < (int)n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ld PI = acos(-1);
const ld EPS = 1e-8;
const ll MOD = 1e9 + 7;
const int M = 1005;
const ll INF = 1e9 + 10;
const int N = 1e6 + 10;

pair <int, int> a[N], b[N];

bool cmp(pair <int, int> a, pair <int, int> b) {
    return a.second < b.second;
}

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    fr(i, n) {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(b, b + n);
    reverse(b, b + n);

    fr(i, n)
        b[i].first = a[i].first;
    sort(b, b + n, cmp);
    fr(i, n)
        cout << b[i].first << " ";
}