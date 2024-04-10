#include <bits/stdc++.h>

using namespace std;

struct state{
    int msk, cnt;
};

int N;
int arr[1005];
int dp[1<<8][1005];
int pre[8][1005];
deque<state> dq;

int bs(int idx, int v, int len){
    int l = idx, r = N, ret = N+1;
    while(l <= r){
        int mid = (l+r)>>1;
        if(pre[v][mid]-pre[v][idx] >= len){
            r = mid - 1;
            ret = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return ret;
}

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        arr[i]--;
        pre[arr[i]][i]++;
    }
    for(int i =1; i<=N; i++){
        for(int j= 0; j<8; j++){
            pre[j][i] += pre[j][i-1];
        }
    }
    for(int i = 0; i<256; i++){
        for(int j = 1; j<=N; j++){
            dp[i][j] = INT_MAX>>1;
        }
    }
    int ans = 0;
    for(int l = 0; l<=N/6; l++){
        dq.push_back({0, 0});
        dp[0][0] = 0;
        while(dq.size()){
            state s = dq.front();
            dq.pop_front();
            if(s.msk == (1<<8)-1){
                ans = max(s.cnt, ans);
            }
            int idx = dp[s.msk][s.cnt];
            for(int v = 0; v<8; v++){
                if((1<<v)&s.msk){
                    continue;
                }
                int idx1 = bs(idx, v, l), idx2 = bs(idx, v, l+1);
                if(idx1 != N+1){
                    if(dp[s.msk|(1<<v)][s.cnt+l] == INT_MAX>>1){
                        dq.push_back({s.msk|(1<<v), s.cnt+l});
                    }
                    dp[s.msk|(1<<v)][s.cnt+l] = min(dp[s.msk|(1<<v)][s.cnt+l], idx1);
                }
                if(idx2 != N+1){
                    if(dp[s.msk|(1<<v)][s.cnt+l+1] == INT_MAX>>1){
                        dq.push_back({s.msk|(1<<v), s.cnt+l+1});
                    }
                    dp[s.msk|(1<<v)][s.cnt+l+1] = min(dp[s.msk|(1<<v)][s.cnt+l+1], idx2);
                }
            }
            dp[s.msk][s.cnt] = INT_MAX>>1;
        }
    }
    cout << ans << endl;
}