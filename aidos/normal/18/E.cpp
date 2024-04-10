#include <bits/stdc++.h>

using namespace std;
int n, m;
string s[555];
int cnt[555][27][2];
int dp[555][27][27];
int A[555][27][27];
int B[555][27][27];

void rec(int r, int a, int b){
    if(r == 0) return;
    rec(r-1, A[r][a][b], B[r][a][b]);
    for(int i = 0; i < m; i++){
        if(i&1) cout << char(b + 'a');
        else cout << char(a+'a');
    }
    cout << "\n";
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < 26; j++) {
            for(int k = 0; k < 26; k++){
                dp[i][j][k] = i?(n * m + 1):0;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cnt[i][s[i][j] - 'a'][j % 2]++;
        }
    }
    for(int i = 0; i < n; i++){
        vector< tuple<int, int, int> > v;
        for(int j=0; j < 26; j++){
            for(int k = 0; k < 26; k++){
                if(j != k){
                    v.push_back(make_tuple(dp[i][j][k], j, k));
                }
            }
        }
        sort(v.begin(), v.end());
        for(int j=0; j < 26; j++){
            for(int k = 0; k < 26; k++){
                if(j != k){
                    int ind = 0;
                    while(get<1>(v[ind]) == j || get<2>(v[ind]) == k) ind++;
                    int a = get<1>(v[ind]);
                    int b = get<2>(v[ind]);
                    dp[i+1][j][k] = dp[i][a][b] + m - cnt[i][j][0] - cnt[i][k][1];
                    A[i+1][j][k] = a;
                    B[i+1][j][k] = b;
                }
            }
        }
    }
    int lastA = -1;
    int lastB = -1;
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            if(i == j) continue;
            if(lastA == -1 || dp[n][lastA][lastB] > dp[n][i][j]){
                lastA = i;
                lastB = j;
            }
        }
    }
    cout << dp[n][lastA][lastB] << "\n";
    rec(n, lastA, lastB);
    return 0;
}