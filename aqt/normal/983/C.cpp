#include <bits/stdc++.h>

using namespace std;

struct state{
    int f, m, i;
};

int N;
map<vector<int>, int> mp1;
vector<int> mp2[1005];
vector<int> v;
int idx;
int dist[11][1005][2005];
bool vis[11][1005][2005];
pair<int, int> arr[2005];
queue<state> qu;

void rec(int n){
    if(n == 10){
        mp1[v] = ++idx;
        mp2[idx] = v;
        return;
    }
    rec(n+1);
    if(v.size() < 4){
        v.push_back(n);
        rec(n);
        v.pop_back();
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    rec(1);
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    vis[1][1][0] = 1;
    qu.push({1, 1, 0});
    while(qu.size()){
        state s = qu.front();
        //cout << s.f << " " << s.m << " " << s.i << endl;
        qu.pop();
        vector<int> t;
        for(int k : mp2[s.m]){
            t.push_back(k);
        }
        if(find(t.begin(), t.end(), s.f) != t.end()){
            t.erase(find(t.begin(), t.end(), s.f));
            int n = mp1[t];
            if(!vis[s.f][n][s.i]){
                vis[s.f][n][s.i] = 1;
                dist[s.f][n][s.i] = dist[s.f][s.m][s.i] + 1;
                qu.push({s.f, n, s.i});
            }
        }
        else if(s.f == arr[s.i+1].first && t.size() < 4){
            t.push_back(arr[s.i+1].second);
            sort(t.begin(), t.end());
            int n = mp1[t];
            if(!vis[s.f][n][s.i+1]){
                vis[s.f][n][s.i+1] = 1;
                dist[s.f][n][s.i+1] = dist[s.f][s.m][s.i] + 1;
                qu.push({s.f, n, s.i+1});
            }
        }
        else{
            if(s.f > 1 && !vis[s.f-1][s.m][s.i]){
                vis[s.f-1][s.m][s.i] = 1;
                dist[s.f-1][s.m][s.i] = dist[s.f][s.m][s.i] + 1;
                qu.push({s.f-1, s.m, s.i});
            }
            if(s.f < 9 && !vis[s.f+1][s.m][s.i]){
                vis[s.f+1][s.m][s.i] = 1;
                dist[s.f+1][s.m][s.i] = dist[s.f][s.m][s.i] + 1;
                qu.push({s.f+1, s.m, s.i});
            }
        }
    }
    int ans = INT_MAX/2;
    for(int i = 1; i<=10; i++){
        if(vis[i][1][N]){
            ans = min(ans, dist[i][1][N]);
        }
    }
    cout << ans << endl;
}