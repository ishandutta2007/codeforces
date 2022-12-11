#include <bits/stdc++.h>

using namespace std;

int N, K, L;
int pre[1000005];
long long dp[1000005];
int cnt[1000005];
string s;

pair<int, int> chk(long long C){
    fill(dp+1, dp+1+N, 0);
    fill(cnt+1, cnt+1+N, 0);
    for(int i = 1; i<=N; i++){
        dp[i] = dp[i-1];
        cnt[i] = cnt[i-1];
        if(i >= L){
            long long v = dp[i-L] + pre[i] - pre[i - L] - C;
            if((dp[i] == v && cnt[i-L]+1 < cnt[i]) || (dp[i] < v)){
                dp[i] = v;
                cnt[i] = cnt[i-L] + 1;
            }
        }
        else{
            long long v = pre[i] - C;
            if((dp[i] < v)){
                dp[i] = v;
                cnt[i] = 1;
            }
        }
    }
    return {dp[N], cnt[N]};
}

int solve(char lb, char ub){
    for(int i = 1; i<=N; i++){
        pre[i] = (s[i-1] >= lb && s[i-1] <= ub);
        pre[i] += pre[i-1];
    }
    long long l = 0, r = N+1;
    int ret = 0;
    while(l <= r){
        long long mid = (l+r)/2;
        auto res = chk(mid);
        if(res.second <= K){
            ret = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return pre[N] - (chk(ret).first + 1LL*K*ret);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K >> L >> s;
    int ret = min(solve('a', 'z'), solve('A', 'Z'));
    cout << ret << endl;
}