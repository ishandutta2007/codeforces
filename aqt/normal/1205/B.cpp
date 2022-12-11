#include <bits/stdc++.h>

using namespace std;

int N;
long long arr[100005];
set<long long> st;
vector<int> graph[1000];
int cnt[65];
int dist[1000][1000];
int par[1000];
deque<int> dq;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i =1 ;i <=N; i++){
        cin >> arr[i];
        if(arr[i] == 0){
            continue;
        }
        st.insert(arr[i]);
        for(long long b = 0; b<60; b++){
            if((1LL<<b)&arr[i]){
                cnt[b]++;
            }
        }
    }
    for(int s = 0; s<60; s++){
        if(cnt[s] >= 3){
            cout << 3 << endl;
            return 0;
        }
    }
    sort(arr+1, arr+1+N, greater<long long>());
    N = 1;
    while(arr[N]){
        N++;
    }
    N--;
    assert(N <= 999);
    int ans = 1000;
    for(int s = 1; s<=N; s++){
        dq.push_back(s);
        for(int n = 1; n<=N; n++){
            dist[s][n] = 1000;
            par[n] = 0;
        }
        dist[s][s] = 0;
        while(dq.size()){
            int n = dq.front();
            dq.pop_front();
            for(int k = 1; k<=N; k++){
                if((arr[k]&arr[n])&& k != n){
                    if(dist[s][k] > dist[s][n] + 1){
                        dist[s][k] = dist[s][n] + 1;
                        par[k] = n;
                        dq.push_back(k);
                    }
                    else if(par[n] != k){
                        ans = min(ans, dist[s][n]+1+dist[s][k]);
                    }
                }
            }
        }
    }
    if(ans == 1000){
        ans = -1;
    }
    cout << ans << endl;
}