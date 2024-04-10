#include <bits/stdc++.h>

#define fc first
#define sc second
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;

const int MAXN = 1001;
set <pair <int, int> > e;

int main() {
    ios_base::sync_with_stdio(0);
    #ifdef __linux__
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, k, a, b, c, d;
    cin >> n >> k >> a >> b >> c >> d;    
    if (n == 4) {
        cout << -1 << endl;
        return 0;
    }
    vector <int> p;
    for (int i = 1; i <= n; i++) {
        if (i != a && i != b && i != c && i != d) {
            p.push_back(i);
        }
    }
    vector <int> a1, b1;
    a1.push_back(a);
    a1.push_back(c);
    for (int i = 0; i < (int) p.size(); i++) {
        a1.push_back(p[i]);
    }
    a1.push_back(d);
    a1.push_back(b);
    b1.push_back(c);
    b1.push_back(a);
    for (int i = 0; i < (int) p.size(); i++) {
        b1.push_back(p[i]);
    }
    b1.push_back(b);
    b1.push_back(d);
    for (int i = 0; i < (int) a1.size() - 1; i++) {
        e.insert({min(a1[i], a1[i + 1]), max(a1[i], a1[i + 1])});
    }
    for (int i = 0; i < (int) b1.size() - 1; i++) {
        e.insert({min(b1[i], b1[i + 1]), max(b1[i], b1[i + 1])});
    }
    if (e.size() > k) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < (int) a1.size(); i++) {
            cout << a1[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < (int) b1.size(); i++) {
            cout << b1[i] << " ";
        }
        cout << endl;
    }
}