#include <bits/stdc++.h>

using namespace std;

vector<int> arr[100005], graph[100005];
int N, M;
bool tkn[100005];
bool stk[100005];
vector<int> ans;

bool dfs(int n){
    tkn[n] = 1;
    stk[n] = 1;
    ans.push_back(n);
    for(int e : graph[n]){
        if(stk[e]){
            return false;
        }
        else if(!tkn[e]){
            if(!dfs(e)){
                return false;
            }
        }
    }
    stk[n] = 0;
    return true;
}

int main(){
    cin >> N >> M;
    bool pos = 1;
    for(int i =1; i<=N; i++){
        int k;
        cin >> k;
        for(int j = 1; j<=k; j++){
            int n;
            cin >> n;
            arr[i].push_back(n);
        }
        for(int j = 0; j<min(arr[i].size(), arr[i-1].size()); j++){
            if(arr[i][j] != arr[i-1][j]){
                graph[arr[i][j]].push_back(arr[i-1][j]);
                break;
            }
            else if(j == min(arr[i].size(), arr[i-1].size())-1){
                if(arr[i].size() < arr[i-1].size()){
                    pos = 0;
                }
            }
        }
    }
    for(int i= 1; i<=M; i++){
        sort(graph[i].begin(), graph[i].end());
        graph[i].erase(unique(graph[i].begin(), graph[i].end()), graph[i].end());
    }
    for(int i= 1; i<=M; i++){
        for(int e : graph[i]){
            if(i < e){
                if(!tkn[e] && !dfs(e)){
                    pos = 0;
                }
            }
        }
    }
    for(int i = 1; i<=M; i++){
        for(int e : graph[i]){
            if(i < e){
                if(tkn[i] == tkn[e]){
                    pos = 0;
                }
            }
        }
    }
    if(pos){
        printf("Yes\n");
        printf("%d\n", ans.size());
        for(int n : ans){
            printf("%d ", n);
        }
    }
    else{
        printf("No\n");
    }
}