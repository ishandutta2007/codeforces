#include <bits/stdc++.h>

using namespace std;

vector <int> ans;

/*int go(int i, const vector <int> &a) {
    cout << i << ":\n";
    if (i == a.size() - 1) return 0;
    int l = i, r = a.size();
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (a[m] > 2 * a[i]) r = m;
        else l = m;
    }
    if (l == i) return 0;
    if (ans[l] != -1) return ans[l];
    ans[l] = go(l, a) + 1;
}*/

int go(int i, const vector <int> &a) {
    if (i == a.size() - 1)
        return 1;
    if (ans[i] != -1) return ans[i];
    if (a[i + 1] > a[i] * 2) {
        return 1;
    }
    ans[i] = go(i + 1, a) + 1;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ans.resize(n, -1);
    go(3, a);
    //int ans = 1;
    /*for (int i = 0; i < n; i++) {
        go(i, a);
        /*int l = i, r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (a[m] > 2 * a[i]) r = m;
            else l = m;
        }
        ans = max(ans, l - i + 1);
        cout << l << " ";
    }*/
    for (int i = 0; i < n; i++) ans[i] = go(i, a);
    //for (int i = 0; i < n; i++) cout << ans[i] << " ";

    cout << *max_element(ans.begin(), ans.end());
    //cout << ans;
    return 0;
}