#include <bits/stdc++.h>

using namespace std;

int N ,M;
string s;

int par[2500];
bool graph[2500][2500];
int dgr[2500];
int val[2500];
bool tkn[2500];

int getrt(int n){
    return par[n] = (par[n] == n ? n : getrt(par[n]));
}

int main(){
    cin >> N >> M;
    for(int i= 1; i<=N+M; i++){
        par[i] = i;
    }
    for(int i= 1; i<=N; i++){
        cin >> s;
        for(int j = 1; j<=M; j++){
            if(s[j-1] == '='){
                int a = getrt(i), b = getrt(N+j);
                par[a] = b;
            }
            else if(s[j-1] == '<'){
                graph[i][N+j] = 1;
            }
            else{
                graph[N+j][i] = 1;
            }
        }
    }
    deque<int> dq;
    for(int i = 1; i<=N+M; i++){
        int n = getrt(i);
        for(int e = 1; e<=N+M; e++){
            graph[n][getrt(e)] |= graph[i][getrt(e)];
            graph[getrt(e)][n] |= graph[getrt(e)][i];
        }
    }
    for(int i= 1; i<=N+M; i++){
        int n = getrt(i);
        dgr[n] = 0;
        for(int e = 1; e<=N+M; e++){
            if(getrt(e) == e){
                dgr[n] += graph[e][n];
            }
        }
        if(!dgr[n] && !tkn[n]){
            tkn[n] = 1;
            val[n] = 1;
            dq.push_back(n);
        }
    }
    while(dq.size()){
        int n = dq.front();
        dq.pop_front();
        for(int e = 1; e<=N+M; e++){
            if(graph[n][e] && getrt(e) == e){
                val[e] = max(val[n]+1, val[e]);
                dgr[e]--;
                if(!dgr[e]){
                    dq.push_back(e);
                }
            }
        }
    }
    for(int i = 1; i<=N+M; i++){
        if(dgr[getrt(i)]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    for(int i =1 ; i<=N; i++){
        cout << val[getrt(i)] << " ";
    }
    cout << endl;
    for(int i = N+1; i<=N+M; i++){
        cout << val[getrt(i)] << " ";
    }
}