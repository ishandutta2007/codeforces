#include <bits/stdc++.h>

using namespace std;

int N, M, K, L;
int m[2][10][4];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K >> L;
    for(int k = 1; k<=K; k++){
        for(int j = 0; j<4; j++){
            m[1][k][j] = INT_MAX/2;
            m[0][k][j] = INT_MIN/2;
        }
    }
    for(int i =1 ; i<=N; i++){
        for(int j = 1; j<=M ;j++){
            int k;
            cin >> k;
            for(int a = 0; a<4; a++){
                int crnt = 0;
                if(a&1){
                    crnt += i;
                }
                else{
                    crnt -= i;
                }
                if(a&2){
                    crnt += j;
                }
                else{
                    crnt -= j;
                }
                m[0][k][a] = max(m[0][k][a], crnt);
                m[1][k][a] = min(m[1][k][a], crnt);
            }
        }
    }
    int lst = 0, ans = 0;
    cin >> lst;
    for(int i = 2; i<=L; i++){
        int c;
        cin >> c;
        for(int k = 0; k<4; k++){
            ans = max(ans, m[0][c][k] - m[1][lst][k]);
        }
        lst = c;
    }
    cout << ans << endl;
}