#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    ll res=0;
    for(int o=0;o<n;o++) for(int i=0;i<n;i++) for(int j=0;j<n;j++) res=max(res,a[o]|a[i]|a[j]);
    cout << res << "\n";
    return 0;
}