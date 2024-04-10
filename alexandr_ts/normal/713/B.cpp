#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e5 + 1;
const int M = 19;
const ld EPS = 1e-10;
const int INF = 2e9 + 1;
const ll MOD = 1e9 + 7;

int a[(1 << M)];

int main() {
    //freopen ("manyangle.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    int l = 0, r = n;
    while (r - l > 1) {
        int m = (r + l) / 2;
        cout << "? 1 1 " << n << " " << m << endl;
        int x;
        cin >> x;
        if (x >= 2)
            r = m;
        else
            l = m;
    }
    int l2 = r;

    l = 0, r = n;
    while (r - l > 1) {
        int m = (r + l) / 2;
        cout << "? 1 1 " << n << " " << m << endl;
        int x;
        cin >> x;
        if (x >= 1)
            r = m;
        else
            l = m;
    }
    int l1 = r;

    l = 1, r = n + 1;
    while (r - l > 1) {
        int m = (r + l) / 2;
        cout << "? 1 " << m << " " << n << " " << n << endl;
        int x;
        cin >> x;
        if (x >= 2)
            l = m;
        else
            r = m;
    }
    int r2 = l;

    l = 1, r = n + 1;
    while (r - l > 1) {
        int m = (r + l) / 2;
        cout << "? 1 " << m << " " << n << " " << n << endl;
        int x;
        cin >> x;
        if (x >= 1)
            l = m;
        else
            r = m;
    }
    int r1 = l;

    ///another side

    l = 0, r = n;
    while (r - l > 1) {
        int m = (r + l) / 2;
        cout << "? 1 1 " << m << " " << n << endl;
        int x;
        cin >> x;
        if (x >= 2)
            r = m;
        else
            l = m;
    }
    int u2 = r;

    l = 0, r = n;
    while (r - l > 1) {
        int m = (r + l) / 2;
        cout << "? 1 1 " << m << " " << n << endl;
        int x;
        cin >> x;
        if (x >= 1)
            r = m;
        else
            l = m;
    }
    int u1 = r;

    l = 1, r = n + 1;
    while (r - l > 1) {
        int m = (r + l) / 2;
        cout << "? " << m << " 1 " << n << " " << n << endl;
        int x;
        cin >> x;
        if (x >= 2)
            l = m;
        else
            r = m;
    }
    int d2 = l;

    l = 1, r = n + 1;
    while (r - l > 1) {
        int m = (r + l) / 2;
        cout << "? " << m << " 1 " << n << " " << n << endl;
        int x;
        cin >> x;
        if (x >= 1)
            l = m;
        else
            r = m;
    }
    int d1 = l;


//    cout << l2 << " " << l1 << " " << r2 << " " << r1 << endl;
//    cout << u2 << " " << u1 << ' ' << d2 << " " << d1 << endl;

    int x1, x2;
///13

    cout << "? " << d2 << " " << r2 << " " << u1 << " " << l1 << endl;
    cin >> x1;
    cout << "? " << d1 << " " << r1 << " " << u2 << " " << l2 << endl;
    cin >> x2;
    if (x1 == 1 && x2 == 1) {
        cout << "! " << d2 << " " << r2 << " " << u1 << " " << l1 << " " <<
                        d1 << " " << r1 << " " << u2 << " " << l2;
        return 0;
    }


    cout << "? " << d2 << " " << r1 << " " << u1 << " " << l2 << endl;
    cin >> x1;
    cout << "? " << d1 << " " << r2 << " " << u2 << " " << l1 << endl;
    cin >> x2;
    if (x1 == 1 && x2 == 1) {
        cout << "! " << d2 << " " << r1 << " " << u1 << " " << l2 << " " <<
                        d1 << " " << r2 << " " << u2 << " " << l1;
        return 0;
    }

///14
    if (r1 <= l1) {
        cout << "? " << d2 << " " << r2 << " " << u1 << " " << l2 << endl;
        cin >> x1;
        cout << "? " << d1 << " " << r1 << " " << u2 << " " << l1 << endl;
        cin >> x2;
        if (x1 == 1 && x2 == 1) {
            cout << "! " << d2 << " " << r2 << " " << u1 << " " << l2 << " " <<
                            d1 << " " << r1 << " " << u2 << " " << l1;
            return 0;
        }


        cout << "? " << d2 << " " << r1 << " " << u1 << " " << l1 << endl;
        cin >> x1;
        cout << "? " << d1 << " " << r2 << " " << u2 << " " << l2 << endl;
        cin >> x2;
        if (x1 == 1 && x2 == 1) {
            cout << "! " << d2 << " " << r1 << " " << u1 << " " << l1 << " " <<
                            d1 << " " << r2 << " " << u2 << " " << l2;
            return 0;
        }
    }

/// 23
    if (d1 <= u1) {
        cout << "? " << d2 << " " << r2 << " " << u2 << " " << l1 << endl;
        cin >> x1;
        cout << "? " << d1 << " " << r1 << " " << u1 << " " << l2 << endl;
        cin >> x2;
        if (x1 == 1 && x2 == 1) {
            cout << "! " << d2 << " " << r2 << " " << u2 << " " << l1 << " " <<
                            d1 << " " << r1 << " " << u1 << " " << l2;
            return 0;
        }


        cout << "? " << d2 << " " << r1 << " " << u2 << " " << l2 << endl;
        cin >> x1;
        cout << "? " << d1 << " " << r2 << " " << u1 << " " << l1 << endl;
        cin >> x2;
        if (x1 == 1 && x2 == 1) {
            cout << "! " << d2 << " " << r1 << " " << u2 << " " << l2 << " " <<
                            d1 << " " << r2 << " " << u1 << " " << l1;
            return 0;
        }
    }

/// 24
    if (r1 <= l1 && d1 <= u1) {
        cout << "? " << d2 << " " << r2 << " " << u2 << " " << l2 << endl;
        cin >> x1;
        cout << "? " << d1 << " " << r1 << " " << u1 << " " << l1 << endl;
        cin >> x2;
        if (x1 == 1 && x2 == 1) {
            cout << "! " << d2 << " " << r2 << " " << u2 << " " << l2 << " " <<
                            d1 << " " << r1 << " " << u1 << " " << l1;
            return 0;
        }


        cout << "? " << d2 << " " << r1 << " " << u2 << " " << l1 << endl;
        cin >> x1;
        cout << "? " << d1 << " " << r2 << " " << u1 << " " << l2 << endl;
        cin >> x2;
        if (x1 == 1 && x2 == 1) {
            cout << "! " << d2 << " " << r1 << " " << u2 << " " << l1 << " " <<
                            d1 << " " << r2 << " " << u1 << " " << l2;
            return 0;
        }
    }
    assert(1 == 0);

}