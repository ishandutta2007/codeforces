#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
const int INF = 2e9 + 1;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-8;
const int MAX = 1e6 + 1;

int a[N], l[N], r[N], hor[N], ans[N];

int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    int cur = a[0];
    fr(i, n)
        hor[i] = min(i + 1, n - i);

    fr(i, n) {
        cur = min(cur, a[i]);
        l[i] = cur;
        cur++;
    }

    cur = a[n - 1];

    for (int i = n - 1; i >= 0; i--) {
        cur = min(cur, a[i]);
        r[i] = cur;
        cur++;
    }

//    fr(i, n)
//        cout << l[i] << " ";cout << endl;
//    fr(i, n)
//        cout << r[i] << " ";cout << endl;
//    fr(i, n)
//        cout << hor[i] << " ";cout << endl;

    fr(i, n)
        ans[i] = min(min(hor[i], l[i]), r[i]);
    cout << *max_element(ans, ans + n);

}