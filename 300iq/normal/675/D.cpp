#include <bits/stdc++.h>

#define mp make_pair 
#define endl '\n'
#define ll long long
#define right pravo
#define left levo
#define fc first
#define sc second
#define mp make_pair

using namespace std;

const int MAXN = 100000;
int pr[MAXN], left[MAXN], right[MAXN], pos[MAXN], ans[MAXN];
 
int main() {
    #ifdef __linux__
        freopen("input.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set <pair <int, int> > d;
    d.insert(mp(a[0], 0));
    for (int i = 1; i < n; i++) {
        set <pair <int, int> > ::iterator it = d.lower_bound(mp(a[i], -1));
        int pos = 0;
        if (it != d.end()) {
            pos = max(pos, it->second);
        }
        if (it != d.begin()) {
            it--;
            pos = max(pos, it->second);
        }
        d.insert(mp(a[i], i));
        cout << a[pos] << " ";
    }
}