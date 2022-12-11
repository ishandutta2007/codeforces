#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

int N, Q;
string s;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> arr[26][12][12];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> Q;
    N = s.size();
    for(int i = 0; i<N; i++){
        for(int j = 1; j<=10; j++){
            arr[s[i]-'A'][j][(i+1)%j].insert(i+1);
        }
    }
    while(Q--){
        int c;
        cin >> c;
        if(c == 1){
            int idx;
            char k;
            cin >> idx >> k;
            for(int j = 1; j<=10; j++){
                arr[s[idx-1]-'A'][j][idx%j].erase(idx);
            }
            s[idx-1] = k;
            for(int j = 1; j<=10; j++){
                arr[s[idx-1]-'A'][j][idx%j].insert(idx);
            }
        }
        else{
            int l, r;
            string t;
            cin >> l >> r >> t;
            int k = t.size();
            int ans = 0;
            for(int i = 0; i<k; i++){
                ans += arr[t[i]-'A'][k][(i+l)%k].order_of_key(r+1)
                - arr[t[i]-'A'][k][(i+l)%k].order_of_key(l);
            }
            cout << ans << "\n";
        }
    }
}