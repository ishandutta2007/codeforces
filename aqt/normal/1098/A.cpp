#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100005], val[100005];
vector<int> graph[100005];
void dfs(int n, int c){
    if(arr[n] == -1){
        if(graph[n].size()){
            int mini = INT_MAX;
            for(int e : graph[n]){
                mini = min(mini, arr[e]);
            }
            if(mini < c){
                cout << -1 << endl;
                exit(0);
            }
            else{
                val[n] = mini - c;
            }
            for(int e : graph[n]){
                dfs(e, val[n] + c);
            }
        }
        else{
            return;
        }
    }
    else{
        if(arr[n] < c){
            cout << -1 << endl;
            exit(0);
        }
        val[n] = arr[n] - c;
        for(int e : graph[n]){
            dfs(e, val[n] + c);
        }
    }
}

int main(){
    cin >> N;
    for(int i = 2; i<=N; i++){
        int p;
        cin >> p;
        graph[p].push_back(i);
    }
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    dfs(1, 0);
    long long tot = 0;
    for(int i = 1; i<=N; i++){
        tot += val[i];
    }
    cout << tot;
}