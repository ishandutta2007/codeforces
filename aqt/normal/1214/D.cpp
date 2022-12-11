#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> mp[1000005];
vector<int> msk[1000005];
int cnt[4000005];

void bfs(int b){
    msk[1][1] |= b;
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=M; j++){
            if(mp[i][j] == 1){
                continue;
            }
            if(i > 1 && (msk[i-1][j]&b)){
                msk[i][j] |= b;
            }
            if(j > 1 && (msk[i][j-1]&b)){
                msk[i][j] |= b;
            }
        }
    }
}


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i<=M+1; i++){
        mp[0].push_back(1);
        mp[N+1].push_back(1);
    }
    for(int i = 1; i <=N; i++){
        msk[i].resize(M+2);
        string s;
        cin >> s;
        mp[i].push_back(1);
        for(char c : s){
            if(c == '#'){
                mp[i].push_back(1);
            }
            else{
                mp[i].push_back(0);
            }
        }
        mp[i].push_back(1);
    }
    bfs(1);
    for(int i = 1; i<=N; i++){
        reverse(msk[i].begin(), msk[i].end());
        reverse(mp[i].begin(), mp[i].end());
    }
    for(int i = 1; i<=N/2; i++){
        swap(msk[i], msk[N-i+1]);
        swap(mp[i], mp[N-i+1]);
    }
    bfs(2);
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=M; j++){
            if(msk[i][j] == 3){
                cnt[i+j]++;
            }
        }
    }
    int ans = 2;
    for(int k=3; k<N+M; k++){
        ans = min(ans, cnt[k]);
    }
    cout << ans << endl;
}