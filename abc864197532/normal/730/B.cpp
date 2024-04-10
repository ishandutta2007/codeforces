#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "! 1 1" << endl;
        fflush(stdout);
        return;
    }
    set <int> minn, maxx;
    char c;
    for (int i = 0; i < n - 1; i += 2) {
        cout << "? " << i + 1 << ' ' << i + 2 << endl;
        cin >> c;
        fflush(stdout);
        if (c == '>') {
            minn.insert(i + 2);
            maxx.insert(i + 1);
        } else {
            minn.insert(i + 1);
            maxx.insert(i + 2);
        }
    }
    if (n & 1) {
        cout << "? " << n - 1 << ' ' << n << endl;
        cin >> c;
        fflush(stdout);
        if (c == '>') {
            if (minn.count(n - 1)) minn.erase(n - 1);
            minn.insert(n);
        } else {
            if (maxx.count(n - 1)) maxx.count(n - 1);
            maxx.insert(n);
        }
    }
    while (minn.size() > 1) {
        set <int> neww;
        while (minn.size() > 1) {
            int a = *minn.begin();
            minn.erase(minn.begin());
            int b = *minn.begin();
            minn.erase(minn.begin());
            cout << "? " << a << ' ' << b << endl;
            cin >> c;
            fflush(stdout);
            if (c == '>') {
                neww.insert(b);
            } else {
                neww.insert(a);
            }
        }
        for (int i : neww) minn.insert(i);
    }
    while (maxx.size() > 1) {
        set <int> neww;
        while (maxx.size() > 1) {
            int a = *maxx.begin();
            maxx.erase(maxx.begin());
            int b = *maxx.begin();
            maxx.erase(maxx.begin());
            cout << "? " << a << ' ' << b << endl;
            cin >> c;
            fflush(stdout);
            if (c == '<') {
                neww.insert(b);
            } else {
                neww.insert(a);
            }
        }
        for (int i : neww) maxx.insert(i);
    }
    cout << "! " << *minn.begin() << ' ' << *maxx.begin() << endl;
    fflush(stdout);
    return;
}


int main () {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}