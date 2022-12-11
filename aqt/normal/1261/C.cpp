#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<bool> arr[1000005];
vector<bool> brr[1000005];
pair<int, int> dq[4000005];
vector<int> dist[2][1000005];

void add(int n, bool b){
    arr[n].push_back(b);
    brr[n].push_back(b);
    dist[0][n].push_back(INT_MAX>>1);
    dist[1][n].push_back(INT_MAX>>1);
}

void bfs(int t, int l, int r){
    while(l <= r){
        auto p = dq[l];
        int i = p.first, j = p.second;
        l++;
        for(int a = -1; a<=1; a++){
            for(int b = -1; b<=1; b++){
                if(!t){
                    if(arr[i+a][j+b] && dist[t][i+a][j+b] > dist[t][i][j] + 1){
                        dist[t][i+a][j+b] = dist[t][i][j] + 1;
                        dq[++r] = {i+a, j+b};
                    }
                }
                else{
                    if(i+a >= 0 && i+a <= N+1 && j+b >= 0 && j+b <= M+1 &&
                       dist[t][i+a][j+b] > dist[t][i][j] + 1){
                        dist[t][i+a][j+b] = dist[t][i][j] + 1;
                        dq[++r] = {i+a, j+b};
                    }
                }
            }
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int j = 0; j<=M+1; j++){
        add(0, 0);
        add(N+1, 0);
    }
    for(int i = 1; i<=N; i++){
        add(i, 0);
        for(int j = 1; j<=M; j++){
            char c;
            cin >> c;
            add(i, (c == 'X'));
        }
        add(i, 0);
    }
    int l = 1, r = 0;
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=M; j++){
            if(arr[i][j]){
                bool edge = 0;
                for(int a = -1; a<=1; a++){
                    for(int b = -1; b<=1; b++){
                        if(!arr[i+a][j+b]){
                            edge = 1;
                        }
                    }
                }
                if(edge){
                    dist[0][i][j] = 0;
                    dq[++r] = {i, j};
                }
            }
        }
    }
    bfs(0, l, r);
    int lft = 0, rht = N, ans = 0;
    while(lft <= rht){
        int mid = lft+rht>>1;
        l = 1, r = 0;
        for(int i = 0; i<=N+1; i++){
            for(int j = 0; j<=M+1; j++){
                dist[1][i][j] = INT_MAX>>1;
                if(arr[i][j] && dist[0][i][j] >= mid){
                    dq[++r] = {i, j};
                    dist[1][i][j] = 0;
                }
            }
        }
        bfs(1, l, r);
        bool good = 1;
        for(int i = 0; i<=N+1; i++){
            for(int j = 0; j<=M+1; j++){
                if(!arr[i][j]){
                    if(dist[1][i][j] <= mid){
                        good = 0;
                        break;
                    }
                }
                else{
                    if(dist[1][i][j] > mid){
                        good = 0;
                        break;
                    }
                }
            }
        }
        if(good){
            lft = mid + 1;
            ans = mid;
        }
        else{
            rht = mid - 1;
        }
    }
    cout << ans << "\n";
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=M; j++){
            if(arr[i][j] && dist[0][i][j] >= ans){
                cout << 'X';
                //cout << dist[0][i][j];
            }
            else{
                cout << '.';
                //cout << dist[0][i][j];
            }
        }
        cout << "\n";
    }
}