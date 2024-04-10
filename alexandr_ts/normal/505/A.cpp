#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e5 + 10;
const ll INF = 2e9;
const ll MAX = 2e6 + 1;
const ll ALPH = 300;
const int MOD = 1e9 + 7;

struct pt {
    ll x, y;
};

pt a[N], b[N];

bool check(string s) {
    fr(i, s.size() / 2)
        if (s[i] != s[(int)s.size() - 1 - i])
            return false;
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    string s;
    cin >> s;
    fr(i, s.size() + 1)
        for (char ch = 'a'; ch <= 'z'; ch++) {
            string tmp;
            fr(j, i)
                tmp += s[j];
            tmp += ch;
            frab(j, i, s.size())
                tmp += s[j];
            if (check(tmp)) {
                cout << tmp;
                return 0;
            }
        }
    cout << "NA";
}