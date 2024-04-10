#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define frb(i, n) for (int i = n - 1; i >= 0; i--)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e3;
const int INF = 2 * 1e9 + 1;

vector <string> a;

bool cmp(string a, string b) {
    if (a.size() > b.size())
        return false;
    if (a.size() < b.size())
        return true;
    return a < b;
}

int main() {
    //freopen("a.in", "r", stdin);
    string n;
    cin >> n;
    for (int len = 1; len < 10; len++)
        for (int mask = 0; mask < (1 << len); mask++) {
            string s = "";
            for (int j = 0; j < len; j++)
                if ((1 << j) & mask)
                    s += '7';
                else
                    s += '4';
            a.pb(s);
        }
    //cout << a.size() << endl;
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < a.size(); i++)
        if (a[i] == n) {
            cout << i + 1;
            return 0;
        }
}