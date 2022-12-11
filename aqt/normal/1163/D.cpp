#include <bits/stdc++.h>

using namespace std;

string s[2], k;
int lps[2][55];
int dp[1005][55][55];
bool vis[1005][55][55];

void build(int idx){
    for(int i = 1, j = 0; i<s[idx].size(); ){
        if(s[idx][i] == s[idx][j]){
            lps[idx][i++] = ++j;
        }
        else if(j == 0){
            lps[idx][i++] = j;
        }
        else{
            j = lps[idx][j-1];
        }
    }
}

int nxt(int typ, int idx, char c){
    while(idx){
        if(s[typ][idx] == c){
            return idx;
        }
        idx = lps[typ][idx-1];
    }
    if(s[typ][0] == c){
        return 0;
    }
    return -1;
}

void upd(int i, int j0, int j1, char c){
    int nj0 = nxt(0, j0, c) + 1, nj1 = nxt(1, j1, c) + 1;
//    cout << nj0 << " " << nj1 << endl;
    int d = 0;
    if(nj0 == s[0].size()){
        d++;
        nj0 = lps[0][nj0-1];
//        cout << c << " " << nj0 << endl;
    }
    if(nj1 == s[1].size()){
        d--;
        nj1 = lps[1][nj1-1];
    }
    if(!vis[i+1][nj0][nj1]){
        vis[i+1][nj0][nj1] = 1;
//        cout << d << endl;
        dp[i+1][nj0][nj1] = dp[i][j0][j1] + d;
    }
    else {
        dp[i+1][nj0][nj1] = max(dp[i][j0][j1] + d, dp[i+1][nj0][nj1]);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> k >> s[0] >> s[1];
    build(0), build(1);
    vis[0][0][0] = 1;
    for(int i = 0; i<k.size(); i++){
        for(int j0 = 0; j0<s[0].size(); j0++){
            for(int j1 = 0; j1<s[1].size(); j1++){
                if(vis[i][j0][j1]){
//                    cout << i<< " " << j0 << " " << j1 << endl;
                    if(k[i] == '*'){
                        for(char c = 'a'; c<='z'; c++){
                            upd(i, j0, j1, c);
                        }
                    }
                    else{
                        upd(i, j0, j1, k[i]);
                    }
                }
            }
        }
    }
    int ans = INT_MIN;
    for(int j0 = 0; j0<s[0].size(); j0++){
        for(int j1 = 0; j1<s[1].size(); j1++){
            if(vis[k.size()][j0][j1]){
                ans = max(ans, dp[k.size()][j0][j1]);
            }
        }
    }
    cout << ans << endl;
}