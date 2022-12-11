#include <bits/stdc++.h>

using namespace std;

int T, N, k1, k2;
vector<int> B;
vector<int> graph[1005];
bool tkn[1005];

int dfs(int n, int p){
    if(tkn[n]){
        return n;
    }
    for(int e : graph[n]){
        if(e != p){
            int k = dfs(e, n);
            if(k){
                return k;
            }
        }
    }
    return 0;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 1; i<N; i++){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        cin >> k1;
        for(int i = 0; i<k1; i++){
            int n;
            cin >> n;
            tkn[n] = 1;
        }
        cin >> k2;
        for(int i = 0; i<k2; i++){
            int n;
            cin >> n;
            B.push_back(n);
        }
        int v;
        cout << "B " << B[0] << endl;
        cin >> v;
        v = dfs(v, 0);
        cout << "A " << v << endl;
        cin >> v;
        if(find(B.begin(), B.end(), v) != B.end()){
            cout << "B " << v << endl;
            cin >> v;
            cout << "C " << v << endl;
        }
        else{
            cout << "C " << -1 << endl;
        }
        for(int i = 1; i<=N; i++){
            graph[i].clear();
        }
        B.clear();
        for(int i= 1; i<=N; i++){
            tkn[i] = 0;
        }
    }
}