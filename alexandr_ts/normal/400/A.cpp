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

int a[N];
vector <pr> ans;

int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    string s;
    fr(i, n) {
        ans.clear();
        cin >> s;
        frab(j, 1, 13)
            if (12 % j == 0) {
                vector <int> cnt(12 / j, 0);
                fr(k, 12)
                    if (s[k] == 'X')
                        cnt[k % (12 / j)]++;
                fr(k, 12 / j)
                    if (cnt[k] == j) {
                        ans.pb(mp(j, 12 / j));
                        break;
                    }
            }
        cout << ans.size() << " ";
        fr(i, ans.size())
            cout << ans[i].first << "x" << ans[i].second << " ";
        cout << endl;
    }
}