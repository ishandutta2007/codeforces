#include <bits/stdc++.h>

using namespace std;

int N, H;
long double p, q;
long double dp[4][2005][2005];
int pos[2005];

double solve(int msk, int l, int r){
    if(l > r){
        return 0;
    }
    if(dp[msk][l][r]+1){
        return dp[msk][l][r];
    }
    int cstll, cstlr, cstrl, cstrr;
    dp[msk][l][r] = 0;
    if(msk&1){
        cstll = min(pos[l] - (pos[l-1] + H), H);
        cstrl = min(pos[r] - (pos[l-1] + H), H);
    }
    else{
        cstll = min(pos[l] - pos[l-1], H);
        cstrl = min(pos[r] - pos[l-1], H);
    }
    if((msk|2) != msk){
        cstlr = min(pos[r+1] - H - pos[l], H);
        cstrr = min(pos[r+1] - H - pos[r], H);
    }
    else{
        cstlr = min(pos[r+1] - pos[l], H);
        cstrr = min(pos[r+1] - pos[r], H);
    }
    //cout << cstll << " " << cstlr << " " << cstrl << " " << cstrr << " " << msk << " " << l << " " << r << endl;
    if(msk&1 && pos[l-1] + H > pos[l]){
        dp[msk][l][r] = solve(msk, l+1, r) + max(0, - (pos[l-1] + H - pos[l]) + cstlr);
    }
    else if((msk|2) != msk && pos[r+1] - H < pos[r]){
        dp[msk][l][r] = solve(msk, l, r-1) + max(0, - (pos[r] - pos[r+1] + H) + cstrl);
    }
    else{
        dp[msk][l][r] += 0.5*p*(solve(msk&2, l+1, r) + cstll);
        dp[msk][l][r] += 0.5*p*(solve(msk&1, l, r-1) + cstrl);
        dp[msk][l][r] += 0.5*q*(solve(msk|1, l+1, r) + cstlr);
        dp[msk][l][r] += 0.5*q*(solve(msk|2, l, r-1) + cstrr);
    }
    //cout << "val: " << msk << " " << l << " " << r << " " << dp[msk][l][r] << endl;
    return dp[msk][l][r];
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> H >> p;
    q = 1-p;
    for(int i = 1; i<=N; i++){
        cin >> pos[i];
    }
    sort(pos+1, pos+1+N);
    pos[0] = -300000010;
    pos[N+1] = -pos[0];
    for(int k = 0; k<4; k++){
        for(int i = 1; i<=N; i++){
            for(int j = i; j<=N;j++){
                dp[k][i][j] = -1;
            }
        }
    }
    cout << setprecision(8) << solve(0, 1, N) << endl;
}