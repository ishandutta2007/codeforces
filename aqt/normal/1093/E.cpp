#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

int N, Q;
tree<int, null_type, less<int>,
rb_tree_tag,tree_order_statistics_node_update> BIT[200005];
int arr[200005], brr[200005];
int vtop[200005];

void add(int p, int idx){
    for(int i = p; i<=N; i+=i&-i){
        BIT[i].insert(idx);
    }
}

void rem(int p, int idx){
    for(int i = p; i<=N; i+=i&-i){
        BIT[i].erase(BIT[i].find(idx));
    }
}

int sum(int p, int b){
    int ret = 0;
    for(int i = p; i>0; i-=i&-i){
        ret += BIT[i].order_of_key(b+1);
    }
    return ret;
}

int main(){
    cin >> N >> Q;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        vtop[arr[i]] = i;
    }
    for(int i = 1; i<=N; i++){
        cin >> brr[i];
        add(i, vtop[brr[i]]);
    }
    while(Q--){
        int c;
        cin >> c;
        if(c == 1){
            int la, ra, lb, rb;
            cin >> la >> ra >> lb >> rb;
            cout << sum(rb, ra) - sum(rb, la-1) - sum(lb-1, ra) + sum(lb-1, la-1) << "\n";
        }
        else{
            int x, y;
            cin >> x >> y;
            rem(x, vtop[brr[x]]);
            rem(y, vtop[brr[y]]);
            swap(brr[x], brr[y]);
            add(x, vtop[brr[x]]);
            add(y, vtop[brr[y]]);
        }
    }
}