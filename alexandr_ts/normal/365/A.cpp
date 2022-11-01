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

bool a[N], b[N];

int main() {
    //freopen("input.txt", "r", stdin);
    int n, k, ans = 0;
    cin >> n >> k;
    fr(i, n) {
        string s;
        cin >> s;
        set <int> st;
        fr(j, s.size())
            if (s[j] - '0' <= k)
                st.insert((int)s[j]);
        if (st.size() == k + 1)
            ans++;
    }
    cout << ans;

}