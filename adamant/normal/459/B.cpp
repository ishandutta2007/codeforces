#include <bits/stdc++.h>
#pragma pack(1)

using namespace std;

#define TASK "test"

int main()
 {
    #ifndef ONLINE_JUDGE
    freopen(TASK".in","r",stdin);
    freopen(TASK".out","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>b[i];
    int r=*max_element(b.begin(),b.end());
    int l=*min_element(b.begin(),b.end());
    cout<<r-l<<endl;
    if(l==r) cout<<1ll*n*(n-1)/2<<endl;
    else cout<<1ll*count(b.begin(),b.end(),r)*count(b.begin(),b.end(),l)<<endl;
 }