#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        vector<int> a(n),b(n);
        for (int &i:a) cin>>i;
        for (int &i:b) cin>>i;

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        bool ok=1;
        for (int i=0;i<n;i++) {
            if (b[i]-a[i] < 0 || b[i]-a[i]>1) ok=0;
        }
        cout<<(ok ? "Yes\n" : "No\n");
    }
}