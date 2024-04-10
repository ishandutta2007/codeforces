#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const ll N = 1e6 + 1;
const ll M = 1e3;
const ld EPS = 1e-8;
const ll INF = 2 * 1e9;

int used[N];

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    fr(i, s.size())
        if (islower(s[i]))
            used[s[i]]++;
        else if (used[tolower(s[i])] <= 0) {
            ans++;
        }
        else {
            used[tolower(s[i])]--;
        }
    cout << ans;
}