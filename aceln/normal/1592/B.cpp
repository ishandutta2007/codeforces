#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while (t--) {
        int n,x; cin>>n>>x;
        vector<int> v(n);
        for (int &i:v) cin>>i;

        vector<int> u=v;
        sort(u.begin(),u.end());

        bool flag=1;
        for (int i=n-x+1;i<=x;i++) {
            if (v[i-1]!=u[i-1]) flag=0;
        }
        cout<<(flag ? "YES\n" : "NO\n");
    }
}