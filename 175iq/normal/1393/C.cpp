#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> a;
int n;
map<int,int> mp;
 
void solve() {
    a.clear();
    mp.clear();
    cin>>n;
    a.resize(n);
    for(int i =0;i<n;i++) {
        cin>>a[i];
        mp[a[i]]++;
    }
    int mx = 0;
    for(auto it: mp) {
        if(it.second>=mx) {
            mx = it.second;
        }
    }
    int cnt = 0;
    for(auto it: mp) {
        if(it.second == mx) {
            cnt++;
        }
    }
    // printf("%d %d %d\n",n,cnt,mx);
    int k = n - (cnt-1);
    // printf("k = %d\n",k);
    int p = max(0,k-mx);
    int ans = p/(mx-1);
    cout<<ans<<"\n";
}
 
int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
}