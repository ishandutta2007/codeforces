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
const ll INF = 2e9 + 1;
const int ST = 110;
const ld EPS = 1e-12;
const ld PI = acos(-1);

string s[4];
int len[4];
vector <int> ans;

int main() {
    //freopen("input.txt", "r", stdin);
    fr(i, 4) {
        char t;
        cin >> t;
        cin >> t;
        cin >> s[i];
        len[i] = s[i].size();
    }
    fr(i, 4) {
        int minl = INF, maxl = -INF;
        fr(j, 4)
            if (i != j)
                minl = min(minl, len[j]), maxl = max(maxl, len[j]);
        //cout << i << " " << len[i] << " " << minl << " " << maxl << endl;
        if (len[i] >= 2 * maxl || len[i] * 2 <= minl)
            ans.pb(i);
    }
    //cout << ans.size() << endl;
    if (ans.size() == 1) {
        cout << (char)(ans[0] + 'A');
    }
    else
        cout << "C";
}