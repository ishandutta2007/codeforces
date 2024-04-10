#include<bits/stdc++.h>
// #include<atcoder/segtree>
using namespace std;
// using namespace atcoder;
const int inf = 1 << 30;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    int mi = inf;
    set<int> se;
    se.insert(-1);
    for(int i = 0; i < n; i++){
        if(A[i] < mi){
            mi = A[i];
            se.insert(i);
        }
    }
    se.insert(inf);
    for(int i = 0; i < m; i++){
        int k, d;
        cin >> k >> d;
        k--;
        if(se.count(k)) se.erase(k);
        A[k] -= d;
        auto it = se.lower_bound(k);
        it--;
        if((*it == -1) || (A[*it] > A[k])){
            se.insert(k);
            it++;
            it++;
            while(1){
                if(*it == inf) break;
                else if(A[k] > A[*it]) break;
                se.erase(it++);
            }
        }
        cout << se.size() - 2;
        if(i == m - 1) cout << "\n";
        else cout << " ";
    }
    
    
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) solve();
}