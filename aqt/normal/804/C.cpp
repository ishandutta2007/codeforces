#include <bits/stdc++.h>

using namespace std;

int N, M;
int clr[300005];
vector<int> graph[300005];
vector<int> lst[300005];

void dfs(int n, int p = 0){
    set<int> st;
    for(int i = 1; i<=lst[n].size(); i++){
        st.insert(i);
    }
    for(int c : lst[n]){
        if(clr[c]){
            st.erase(clr[c]);
        }
    }
    for(int c : lst[n]){
        if(!clr[c]){
            clr[c] = *st.begin();
            st.erase(st.begin());
        }
    }
    for(int e : graph[n]){
        if(e != p){
            dfs(e, n);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    int ans = 1;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        ans = max(ans, n);
        while(n--){
            int c;
            cin >> c;
            lst[i].push_back(c);
        }
    }
    for(int i = 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    cout << ans << "\n";
    for(int i = 1; i<=M; i++){
        cout << max(1, clr[i]) << " ";
    }
}