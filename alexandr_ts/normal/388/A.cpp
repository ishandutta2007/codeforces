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

vector <int> ans[N];
int a[N];

int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    sort(a, a + n);
    //reverse(a, a + n);
    int cur = 0;
    fr(j, n) {
        bool done = false;
        fr(i, cur) {
            if (ans[i].size() <= a[j]) {
                done = true;
                ans[i].pb(a[j]);
                //cout << i << " " <<  j << endl;
                break;
            }
        }
        if (!done) {
                            ans[cur].pb(a[j]);
            cur++;
            //cout << cur << " "  << j << endl;
        }
    }
    cout << cur;
//    cout << endl;
//    fr(i, cur + 1) {
//        fr(j, ans[i].size())
//            cout << ans[i][j] << " " ;cout << endl;}
}