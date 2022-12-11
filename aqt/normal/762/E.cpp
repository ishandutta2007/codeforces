#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

struct event{
    int pos, id;
    operator < (event e) const{
        if(pos == e.pos){
            return id < e.id;
        }
        return pos > e.pos;
    }
};

int N, K;
tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> fre[10105];
priority_queue<event> pq;
int pos[100005], rng[100005], typ[100005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for(int i = 1; i<=N; i++){
        cin >> pos[i] >> rng[i] >> typ[i];
        pq.push({pos[i], i});
        pq.push({pos[i]+rng[i], -i});
    }
    long long ans = 0;
    while(pq.size()){
        event e = pq.top();
        pq.pop();
        if(e.id < 0){
            int id = -e.id;
            fre[typ[id]].erase(pos[id]);
        }
        else{
            for(int k = max(0, typ[e.id]-K); k<=typ[e.id]+K; k++){
                ans += fre[k].size() - fre[k].order_of_key(pos[e.id]-rng[e.id]);
            }
            fre[typ[e.id]].insert(pos[e.id]);
        }
    }
    cout << ans << endl;
}