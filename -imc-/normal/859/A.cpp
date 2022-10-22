#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

void solve(bool read) {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    cout << max(*max_element(all(a)) - 25, 0) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
    return 0;
}