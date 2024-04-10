#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

bool f() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &x:a)
        cin >> x;
    if(!count(a.begin(), a.end(), k))
        return false;
    if(n==1)
        return true;
    for(int i =0; i  < n; ++i)
        for(int j = i + 1; j <= i + 2 && j < n; ++j)
        if(a[i] >= k && a[j] >= k)
            return true;
        return false;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cout << (f() ? "yes" : "no") << '\n';
    }
    return 0;
}