//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
//#define int ll
#define endl '\n'
#define double long double
const int N=1000010;
const ll mod=1000000007;
int a[N];
int c[N];
int ind[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];

    }
//    cout<<endl;
    sort(a+1,a+n+1);
    string s;cin>>s;
    for (int i=0;i<n;i++){
        c[i]=(s[i]=='R');

    }
    for (int i=1;i<=n;i++){
        ind[i]=(c[n-1]+n-i)%2;
    }
//    for (int i=0;i<n;i++) c[i]=rand()%2,cout<<c[i]<<" ";
//    cout<<endl;
    int l=1,r=n;
    vector<pair<int,int> >ans;
    for (int i=n-2;i>=0;i--){

        if (ind[r]==c[i]) ans.push_back({a[l],ind[l]}),l++;
        else ans.push_back({a[r],ind[r]}),r--;
//        cout<<ans.back().first<<endl;
//        cout<<l<<" "<<r<<endl;
    }
    ans.push_back({a[l],ind[l]});
    reverse(ans.begin(),ans.end());
    ll LL=0ll;
    ll RR=0ll;
    for (int i=0;i<n;i++){
        auto cur=ans[i];
        if (cur.second) RR+=ans[i].first;
        else LL+=ans[i].first;

        cout<<cur.first<<" ";
        if (cur.second) cout<<"R\n";
        else cout<<"L\n";
        if ((LL<RR)!=c[i] || LL==RR){
            cout<<"AAAAAAAAAAAAAAAAAAA\n";
            exit(1);
//            return;
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}
/**
13
101 102 103 104 105 106 107 108 109 110 111 112 113
RRRRLRLRLLRLL

13
141 267 334 400 569 624 778 858 962 1064 1105 1245 1381
RRRRLRLRLLRLL
1 1 1 1 0 1 0 1 0 0 1 0 0
**/