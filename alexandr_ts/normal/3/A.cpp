#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 2 * 1e6;
const ld EPS = 1e-8;
const ll INF = 2 * 1e9 + 1;
const ll MAX = 1e9;

vector <string> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    char a1, a2, b1, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    while (a1 < a2 && b1 < b2) {
        ans.pb("RU");
        a1++, b1++;
    }
    while (a1 > a2 && b1 < b2) {
        ans.pb("LU");
        a1--, b1++;
    }
    while (a1 < a2 && b1 > b2) {
        ans.pb("RD");
        a1++, b1--;
    }
    while (a1 > a2 && b1 > b2) {
        ans.pb("LD");
        a1--, b1--;
    }

    while (a1 == a2 && b1 < b2) {
        ans.pb("U");
        b1++;
    }
    while (a1 == a2 && b1 > b2) {
        ans.pb("D");
        b1--;
    }
    while (a1 < a2 && b1 == b2) {
        ans.pb("R");
        a1++;
    }
    while (a1 > a2 && b1 == b2) {
        ans.pb("L");
        a1--;
    }
    cout << ans.size() << endl;
    fr(i, ans.size())
        cout << ans[i] << endl;

}