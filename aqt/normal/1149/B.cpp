#include <bits/stdc++.h>

using namespace std;

int N, Q;
int dp[255][255][255];
string s;
int nxt[26][100005];
vector<char> vec[4];
int sz[4];

int main(){
    cin >> N >> Q >> s;
    for(int c = 0; c<26; c++){
        nxt[c][N+2] = nxt[c][N+1] = N+1;
    }
    for(int i = N; i>0; i--){
        for(int c = 0; c<26; c++){
            nxt[c][i] = nxt[c][i+1];
        }
        nxt[s[i-1]-'a'][i] = i;
    }
    while(Q--){
        char c;
        int t;
        cin >> c >> t;
        if(c == '+'){
            cin >> c;
            vec[t].push_back(c);
            sz[t]++;
            if(t == 1){
                for(int i = 0; i<=sz[2]; i++){
                    for(int j = 0; j<=sz[3]; j++){
                        dp[sz[1]][i][j] = nxt[c-'a'][dp[sz[1]-1][i][j]+1];
                        if(i){
                            dp[sz[1]][i][j] = min(nxt[vec[2][i-1]-'a'][dp[sz[1]][i-1][j]+1],
                                                dp[sz[1]][i][j]);
                        }
                        if(j){
                            dp[sz[1]][i][j] = min(nxt[vec[3][j-1]-'a'][dp[sz[1]][i][j-1]+1],
                                                dp[sz[1]][i][j]);
                        }
                    }
                }
            }
            else if(t == 2){
                for(int i = 0; i<=sz[1]; i++){
                    for(int j = 0; j<=sz[3]; j++){
                        dp[i][sz[2]][j] = nxt[c-'a'][dp[i][sz[2]-1][j]+1];
                        if(i){
                            dp[i][sz[2]][j] = min(nxt[vec[1][i-1]-'a'][dp[i-1][sz[2]][j]+1],
                                                dp[i][sz[2]][j]);
                        }
                        if(j){
                            dp[i][sz[2]][j] = min(nxt[vec[3][j-1]-'a'][dp[i][sz[2]][j-1]+1],
                                                dp[i][sz[2]][j]);
                        }
                    }
                }
            }
            else{
                for(int i = 0; i<=sz[1]; i++){
                    for(int j = 0; j<=sz[2]; j++){
                        dp[i][j][sz[3]] = nxt[c-'a'][dp[i][j][sz[3]-1]+1];
                        if(i){
                            dp[i][j][sz[3]] = min(nxt[vec[1][i-1]-'a'][dp[i-1][j][sz[3]]+1],
                                                dp[i][j][sz[3]]);
                        }
                        if(j){
                            dp[i][j][sz[3]] = min(nxt[vec[2][j-1]-'a'][dp[i][j-1][sz[3]]+1],
                                                dp[i][j][sz[3]]);
                        }
                    }
                }
            }
        }
        else{
            sz[t]--;
            vec[t].pop_back();
        }
        if(dp[sz[1]][sz[2]][sz[3]] <= N){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }
}