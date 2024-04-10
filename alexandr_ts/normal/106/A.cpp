#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e6 + 3;
const ll INF = 2e9;
const ll N = 1e6 + 2;
const ll MAX = 2e5 + 2;
const ld EPS = 1e-6;

ll a[N];

string st = "6789TJQKA";

int pos(char c) {
    fr(i, st.size())
        if (st[i] == c)
            return i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    char mn;
    cin >> mn;
    char m1, m2, n1, n2;
    cin >> n1 >> m1 >> n2 >> m2;
    if (m1 == m2) {
        if (pos(n1) > pos(n2)) {
            cout << "YES";
            return 0;
        }
        else {
            cout << "NO";
            return 0;
        }
    }
    if (m1 == mn) {
        cout << "YES";
        return 0;
    }
    cout << "NO";
}