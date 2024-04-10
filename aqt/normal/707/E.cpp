#include <bits/stdc++.h>

using namespace std;

int N, M, K, Q;
long long BIT[2005][2005];
long long ans[2005];
vector<pair<pair<int, int>, int>> val[2005];
pair<pair<int, int>, pair<int, int>> qu[2005];
bool has[2005][2005];
bool ison[2005];

void upd(int x, int y, long long v){
    for(int i = x; i<=N; i+=i&-i){
        for(int j = y; j<=M; j+=j&-j){
            BIT[i][j] += v;
        }
    }
}

long long query(int x, int y){
    long long s = 0;
    for(int i = x; i>0; i-=i&-i){
        for(int j = y; j>0; j-=j&-j){
            s += BIT[i][j];
        }
    }
    return s;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for(int k = 1; k<=K; k++){
        int L;
        cin >> L;
        for(int l = 1; l<=L; l++){
            int x, y, v;
            cin >> x >> y >> v;
            val[k].push_back({{x, y}, v});
        }
    }
    cin >> Q;
    int idx = 0;
    fill(ison, ison+K+1, 1);
    for(int q = 1; q<=Q; q++){
        string s;
        cin >> s;
        if(s == "ASK"){
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            qu[++idx] = {{x1, y1}, {x2, y2}};
            for(int k = 1; k<=K; k++){
                has[idx][k] = ison[k];
            }
        }
        else{
            int n;
            cin >> n;
            ison[n] ^= 1;
        }
    }
    Q = idx;
    for(int k = 1; k<=K; k++){
        for(auto n : val[k]){
            upd(n.first.first, n.first.second, n.second);
        }
        for(int q = 1; q<=Q; q++){
            if(has[q][k]){
                ans[q] += query(qu[q].second.first, qu[q].second.second);
                ans[q] -= query(qu[q].first.first-1, qu[q].second.second);
                ans[q] -= query(qu[q].second.first, qu[q].first.second-1);
                ans[q] += query(qu[q].first.first-1, qu[q].first.second-1);
            }
        }
        for(auto n : val[k]){
            upd(n.first.first, n.first.second, -n.second);
        }
    }
    for(int q = 1; q<=Q; q++){
        cout << ans[q] << "\n";
    }
}