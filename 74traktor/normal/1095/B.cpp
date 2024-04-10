#include <bits/stdc++.h>

using namespace std;

int a[100005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    multiset < int > g;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        g.insert(a[i]);
    }
    int ans = 1e9;
    for (int i = 1; i <= n; ++i){
        g.erase(g.find(a[i]));
            ans = min(ans, (*g.rbegin()) - (*g.begin()));
        g.insert(a[i]);
    }
    cout << ans << endl;
    return 0;
}