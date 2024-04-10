#include <bits/stdc++.h>

using namespace std;

int N, Q;
int arr[300005];
vector<pair<int ,int>> startp[300005];
bool ans[300005];
int dist[300005][25];
int lst[25];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    for(int i =1; i<=N; i++){
        cin >> arr[i];
    }
    for(int i = 1; i<=Q; i++){
        int l, r;
        cin >> l >> r;
        startp[l].push_back({r, i});
    }
    for(int k = 0; k<20; k++){
        lst[k] = N+1;
        dist[N+1][k] = N+1;
    }
    for(int i = N; i>0; i--){
        for(int k = 0; k<20; k++){
            if((1<<k)&arr[i]){
                dist[i][k] = i;
            }
            else{
                dist[i][k] = N+1;
                for(int b = 0; b<20; b++){
                    if((1<<b)&arr[i]){
                        dist[i][k] = min(dist[lst[b]][k], dist[i][k]);
                    }
                }
            }
        }
        for(int k = 0; k<20; k++){
            if((1<<k)&arr[i]){
                lst[k] = i;
            }
        }
        for(auto p : startp[i]){
            for(int k = 0; k<20; k++){
                if(arr[p.first]&(1<<k)){
                    ans[p.second] |= (dist[i][k] <= p.first);
                }
            }
        }
    }
    for(int i = 1; i<=Q; i++){
        if(ans[i]){
            cout << "Shi" << "\n";
        }
        else{
            cout << "Fou" << "\n";
        }
    }
}