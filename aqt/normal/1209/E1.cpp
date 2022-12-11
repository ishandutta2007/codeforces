#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[13][2005];
int dp[1<<12][2005];
int crnt[1<<12];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> N >> M;
        for(int i = 0; i<N; i++){
            for(int j = 1; j<=M; j++){
                cin >> arr[i][j];
            }
        }
        for(int m = 0; m<1<<N; m++){
            for(int j = 1; j<=M; j++){
                dp[m][j] = 0;
            }
        }
        for(int j =1; j<=M; j++){
            for(int l = 0; l<N; l++){
                for(int m = 0 ; m<1<<N; m++){
                    int s = 0;
                    for(int b = 0; b<N; b++){
                        if((1<<b)&m){
                            s += arr[b][j];
                        }
                    }
                    crnt[m] = max(s, crnt[m]);
                }
                int t = arr[0][j];
                for(int k = 1; k<N; k++){
                    arr[k-1][j] = arr[k][j];
                }
                arr[N-1][j] = t;
            }
            for(int m1 = 0; m1<1<<N; m1++){
                for(int m2 = 0; m2<1<<N; m2++){
                    if(m1&m2){
                        continue;
                    }
                    //cout << m1 << " " << j << " " << crnt[m1] << endl;
                    dp[m1|m2][j] = max(dp[m1|m2][j], dp[m2][j-1]+crnt[m1]);
                }
                crnt[m1] = 0;
                //cout << "here: " << m1 << " " << (j-1) << " " << dp[m1][j-1] << endl;
            }
        }
        cout << dp[(1<<N)-1][M] << "\n";
    }

}