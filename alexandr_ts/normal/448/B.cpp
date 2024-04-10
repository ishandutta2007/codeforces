#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 4e5;
const ll INF = 2e12 + 1;
const int ST = 110;
const ld EPS = 1e-12;
const ld PI = acos(-1);

ll a[N], b[N];

int main() {
    //freopen("input.txt", "r", stdin);
    string s, t;
    cin >> s >> t;
    fr(i, s.size())
        a[s[i]]++;
    fr(i, t.size())
        b[t[i]]++;
    bool aut = (s.size() > t.size());
    int cur2 = 0;
    bool ar = false;
    fr(i, t.size()) {
        while (cur2 < s.size() && t[i] != s[cur2])
            cur2++;
        if (cur2 == (int)s.size()) {
            ar = true;
            break;
        }
        cur2++;
    }
    fr(i, N)
        if (a[i] < b[i]) {
            cout << "need tree";
            return 0;
        }
    if (aut && ar) {
        cout << "both";
    }
    else if (aut) {
        cout << "automaton";
    }
    else
        cout << "array";
}