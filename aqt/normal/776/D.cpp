#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> graph[200005];
bool pari[200005];
int lst[200005];
int low[200005], t=0;
int typ[200005], c=0;
stack<int> stk;

void dfs(int n){
    low[n] = ++t;
    stk.push(n);
    bool isrt = 1;
    for(int e : graph[n]){
        if(!low[e]){
            dfs(e);
        }
        if(low[e] < low[n]){
            isrt = 0;
            low[n] = low[e];
        }
    }
    if(isrt){
        c++;
        while(stk.size()){
            int x = stk.top();
            stk.pop();
            typ[x] = c;
            low[x] = INT_MAX;
            if(x == n){
                break;
            }
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i= 1; i<=N; i++){
        cin >> pari[i];
    }
    swap(N, M);
    for(int i = 1; i<=N; i++){
        int k;
        cin >> k;
        while(k--){
            int n;
            cin >> n;
            if(lst[n]){
                if(!pari[n]){
                    graph[lst[n]+N].push_back(i);
                    graph[i].push_back(lst[n]+N);
                    graph[i+N].push_back(lst[n]);
                    graph[lst[n]].push_back(i+N);
                }
                else{
                    graph[i].push_back(lst[n]);
                    graph[lst[n]].push_back(i);
                    graph[lst[n]+N].push_back(i+N);
                    graph[i+N].push_back(lst[n]+N);
                }
            }
            else{
                lst[n] = i;
            }
        }
    }
    for(int i= 1; i<=2*N; i++){
        if(!low[i]){
            dfs(i);
        }
    }
    for(int i = 1; i<=N; i++){
        if(typ[i] == typ[i+N]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}