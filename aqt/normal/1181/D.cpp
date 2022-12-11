#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
vector<pair<long long, int>> qu, v;
int ans[500005];
int BIT[500005];
int arr[500005];

void upd(int n, int v){
    for(int i = n; i<=M; i+=i&-i){
        BIT[i] += v;
    }
}

int clmb(long long t){
    int s = 0, idx = 0;
    for(int i= 19; i>=0; i--){
        if((1<<i)+idx <= M && BIT[(1<<i)+idx] + s < t){
            idx += (1<<i);
            s += BIT[idx];
        }
    }
    return idx+1;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> Q;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        arr[n]++;
    }
    for(int i = 1; i<=M; i++){
        v.push_back({arr[i], i});
    }
    for(int i = 1; i<=Q; i++){
        long long n;
        cin >> n;
        qu.push_back({n, i});
    }
    sort(qu.begin(), qu.end());
    sort(v.begin(), v.end());
    long long init = N, nxt = N;
    int idx = 0;
    long long cnt = 0;
    for(auto p : qu){
        if(p.first > nxt){
            while(idx < M && nxt < p.first){
                int c = v[idx].first;
                init = nxt;
                while(idx < M && v[idx].first == c){
                    upd(v[idx].second, 1);
                    idx++;
                    cnt++;
                }
                if(idx == M){
                    nxt = LLONG_MAX;
                }
                else{
                    nxt += cnt*(v[idx].first - c);
                }
            }
        }
        long long t = ((p.first - 1 - init)%cnt);
        ans[p.second] = clmb(t+1);
    }
    for(int i = 1; i<=Q; i++){
        cout << ans[i] << "\n";
    }
}