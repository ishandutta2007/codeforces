#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long   ll;
typedef long double ld;
 
#define all(x)  (x).begin(), (x).end()
#define sz(x)   (x).size()
#define pb      push_back
#define mp      make_pair
#define fr      first
#define sc      second
 
string s, t;
int n;
 
void input() {
    cin >> n;
    cin >> s >> t;
}
 
void solve() {
    vector<int> ind;
    for(int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            ind.pb(i);
        }
    }
    if (sz(ind) > 2) {
        puts("No");
        return;
    }
    else if (sz(ind) != 1){
        if (sz(ind) == 2) {swap(s[ind[0]], t[ind[1]]); }
        puts(s == t ? "Yes" : "No");
        return;
    }
    puts("No");
    return;
}
 
int main() {
    int testcases = 1;
    scanf("%d", &testcases);
    while(testcases--) {
        input();
        solve();
    }
    return 0;
}