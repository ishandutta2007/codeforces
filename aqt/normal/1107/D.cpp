#include <bits/stdc++.h>

using namespace std;

int N;
int pre[6000][6000];
string s;

int sum(int r1, int c1, int r2, int c2){
    return pre[r1][c1] - pre[r2][c1] - pre[r1][c2] + pre[r2][c2];
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> s;
        for(int j = 0; j<s.size(); j++){
            int v = s[j] - 'A' + 10;
            if('0' <= s[j] && '9' >= s[j]){
                v = s[j] - '0';
            }
            for(int k = 0; k<4; k++){
                if((1<<k) & v){
                    pre[i][4*j+4-k] = 1;
                }
            }
        }
    }
    for(int i =1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            pre[i][j] += pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        }
    }
    int ans = 1;
    for(int k = 2; k<=N; k++){
        bool pos = !(N%k);
        for(int i = k; i<N+k; i+=k){
            for(int j = k; j<N+k; j+=k){
                int r = min(i, N), c = min(j, N);
                if(!sum(r, c, i-k, j-k) || sum(r, c, i-k, j-k) == (r-(i-k))*(c-(j-k))){
                    continue;
                }
                pos = 0;
            }
        }
        if(pos){
            ans = k;
        }
    }
    cout << ans;
}