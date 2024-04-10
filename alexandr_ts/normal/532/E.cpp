#include <bits/stdc++.h>
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> prl;
typedef pair <int, int> pr;
typedef string str;

const int N = 2 * 1e5;
const ll INF = 1e15;
const ld EPS = 1e-6;


int main() {
    //freopen("a.in", "r", stdin);
    str s, t;
    int n;
    cin >> n;
    cin >> s >> t;
    int curl = 0, curr = n - 1;
    while (s[curl] == t[curl])
        curl++;
    while (s[curr] == t[curr])
        curr--;
    if (curl == curr) {
        cout << 2;
        return 0;
    }
    str s1, t1;
    for (int i = curl; i <= curr; i++)
        s1 += s[i], t1 += t[i];
    int ans = 2;
    for (int i = 0; i < s1.size() - 1; i++)
    if (s1[i] != t1[i + 1]) {
            ans--;break;}
    for (int i = 0; i < s1.size() - 1; i++)
    if (t1[i] != s1[i + 1]) {
            ans--;break;}
    cout << ans;

}