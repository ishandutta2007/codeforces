#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[13][2005];
int dp[1<<12][2005];
int crnt[1<<12];
int srt[2005];
int ta[13], tb[13];

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
                srt[j] = j;
            }
        }
        sort(srt+1, srt+M+1, [](int a, int b){
            int maxA = 0, maxB = 0;
            for(int i = 0; i<N; i++){
                maxA = max(maxA, arr[i][a]);
                maxB = max(maxB, arr[i][b]);
            }
            return maxA > maxB;
        });
        for(int m = 0; m<1<<N; m++){
            for(int j = 1; j<=M; j++){
                dp[m][j] = 0;
            }
        }
        int lst = 0;
        for(int i =1; i<=min(N, M); i++){
            int j = srt[i];
            //cout << "idx: " << j << endl;
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
                for(int m2 = (m1^((1<<N)-1)); ; m2=((m2-1)&((m1^((1<<N)-1))))){
                    //cout << m1 << " " << j << " " << crnt[m1] << endl;
                    dp[m1|m2][j] = max(dp[m1|m2][j], dp[m2][lst]+crnt[m1]);
                    if(m2 == 0){
                        break;
                    }
                }
                crnt[m1] = 0;
                //cout << "here: " << m1 << " " << (j-1) << " " << dp[m1][j-1] << endl;
            }
            lst= j;
        }
        cout << dp[(1<<N)-1][lst] << "\n";
    }

}