#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const ll N = 1e5 + 1;
const ll M = 2 * 1e3 + 1;
const ld EPS = 1e-8;
const ll INF = 2 * 1e9;

bool used[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    vector <int> ans;
    used[0] = used[1] = true;
    frab(i, 2, n + 1)
        for(int j = i * 2; j <= n; j += i)
            used[j] = true;
    fr(i, n + 1)
        if (!used[i])
            for (int j = i; j <= n; j *= i)
                ans.pb(j);
    cout << ans.size() << endl;
    fr(i, ans.size())
        cout << ans[i] << " ";
 }