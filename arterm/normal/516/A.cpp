#include <bits/stdc++.h>

using namespace std;

#define pb push_back

vector<int> a[10];

void pre() {
    a[2].pb(2);

    a[3].pb(3);

    a[4].pb(3);
    a[4].pb(2);
    a[4].pb(2);

    a[5].pb(5);

    a[6].pb(5);
    a[6].pb(3);

    a[7].pb(7);

    a[8].pb(7);
    a[8].pb(2);
    a[8].pb(2);
    a[8].pb(2);

    a[9].pb(7);
    a[9].pb(3);
    a[9].pb(3);
    a[9].pb(2);
}

int main() {
    vector<int> ans;
    pre();
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char ch;
        cin >> ch;
        int x = ch - '0';
        ans.insert(ans.end(), a[x].begin(), a[x].end());
    }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    for (auto x : ans)
        cout << x;
    cout << "\n";
    return 0;
}