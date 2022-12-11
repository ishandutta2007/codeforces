#include <bits/stdc++.h>

using namespace std;

int N;
long long dist[2005];
int x[2005], y[2005];
int val[2005];
bool vis[2005];
pair<int, int> par[2005];
vector<pair<int, int>> edge;
vector<int> pw;

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> x[i] >> y[i];
    }
    for(int i = 1; i<=N; i++){
        cin >> dist[i];
    }
    for(int i = 1; i<=N; i++){
        cin >> val[i];
    }
    long long ans = 0;
    for(int t = 0; t<N; t++){
        int idx = 0;
        long long mini = INT_MAX;
        for(int n = 1; n<=N; n++){
            if(!vis[n] && mini > dist[n]){
                mini = dist[n];
                idx = n;
            }
        }
        vis[idx] = 1;
        for(int n = 1; n<=N; n++){
            if(!vis[n]){
                dist[n] = min(dist[n], 1LL*(val[idx]+val[n])*(abs(x[idx]-x[n]) + abs(y[idx]-y[n])));
                if(dist[n] == 1LL*(val[idx]+val[n])*(abs(x[idx]-x[n]) + abs(y[idx]-y[n]))){
                    par[n] = {n, idx};
                }
            }
        }
        ans += dist[idx];
        if(par[idx].first){
            edge.push_back(par[idx]);
        }
        else{
            pw.push_back(idx);
        }
    }
    cout << ans << endl;
    cout << pw.size() << endl;
    for(int n : pw){
        cout << n << " ";
    }
    cout << endl;
    cout << edge.size() << endl;
    for(auto p : edge){
        cout << p.first << " " << p.second << endl;
    }
}