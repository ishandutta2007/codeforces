#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> Tree;
int main(){
    map<int, Tree> add;
    map<int, Tree> sub;
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        int a, t, x;
        cin >> a>>t>>x;
        if(a == 1){
            add[x].insert(t);
        }
        else if (a== 2){
            sub[x].insert(t);
        }
        else{
            cout << add[x].order_of_key(t) - sub[x].order_of_key(t) << endl;;
        }
    }

    return 0;
}