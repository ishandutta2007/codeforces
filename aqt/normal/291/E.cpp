#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> graph[300005];
string seq[300005];
string s;
int ff[300005][28];
int par[300005];
int ptr[300005];
int ans = 0;

void dfs(int n){
    int i = 0, j = ptr[par[n]];
    for(int i = 0; i<seq[n].size(); i++){
        j = ff[j][seq[n][i]-'a'];
        if(j == M){
            j = ff[j-1][27];
            ans++;
        }
    }
    ptr[n] = j;
    for(int e : graph[n]){
        dfs(e);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 2; i<=N; i++){
        cin >> par[i];
        cin >> seq[i];
        graph[par[i]].push_back(i);
    }
    cin >> s;
    M = s.size();
    for(int i = 1, j = 0; i<M;){
        if(s[i] == s[j]){
            ff[i++][27] = ++j;
        }
        else if(!j){
            i++;
        }
        else{
            j = ff[j-1][27];
        }
    }
    for(int i = 0; i<M; i++){
        int idx = i;
        ff[i][s[idx]-'a'] = idx+1;
        idx = ff[idx-1][27];
        for(int j= 0; j<26; j++){
            ff[i][j] = max(ff[idx][j], ff[i][j]);
        }
    }
    dfs(1);
    cout << ans << "\n";
}