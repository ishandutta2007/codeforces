#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> order(n);
    vector <int> b(n + 1);
    //unordered_set <int> in;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]] = i;
    }
    for (int i = 0; i < n; i++) cin >> order[i];
    int cur = -1;
    for (int i = 0; i < n; i++) {
        if (b[order[i]] > cur) {
            cout << b[order[i]] - cur<< " ";
            cur = b[order[i]];
        }
        else cout << "0 ";
    }
    return 0;
}