#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define fc first
#define sc second
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define int ll
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
#define abs(x) (x > 0 ? x : -x)
  
using namespace std;

map <int, int> cnt;
vector <pair <int, int> > a;
  
main() {
    ios_base::sync_with_stdio(0);
    #ifdef __linux__
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, x, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        cnt[x]++;
    }
    cin >> m;
    a.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i].fc;
    }
    for (int i = 0; i < m; i++) {
        cin >> a[i].sc;
    }
    int ind = 0;
    int ans = -1, ans1 = 0;
    for (int i = 0; i < m; i++) {
        if (cnt[a[i].fc] > ans || (cnt[a[i].fc] == ans && cnt[a[i].sc] > ans1)) {
            ans = cnt[a[i].fc];
            ans1 = cnt[a[i].sc];
            ind = i;
        }
    }
    cout << ind + 1 << endl;
}