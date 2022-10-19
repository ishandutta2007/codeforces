#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while (t--) {
        int n,H; cin>>n>>H;
        vector<int> v(n);
        for (int &i:v) cin>>i;
        sort(v.begin(),v.end());

        int times = H/(v[n-1]+v[n-2])*2;
        int remain = H%(v[n-1]+v[n-2]);
        if (remain==0) cout<<times<<'\n';
        else if (remain<=v[n-1]) cout<<times+1<<'\n';
        else cout<<times+2<<'\n';
    }
}