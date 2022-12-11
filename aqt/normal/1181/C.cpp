#include <bits/stdc++.h>

using namespace std;

int N, M;
char arr[1005][1005];

int main(){
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        string s;
        cin >> s;
        for(int j = 1; j<=M; j++){
            arr[i][j] = s[j-1];
        }
    }
    long long ans = 0;
    for(int i= 1; i<=N; i++){
        for(int j = 1; j<=M; j++){
            if(arr[i-1][j] != arr[i][j]){
                int l = 0;
                for(int k = i; k<=N; k++){
                    if(arr[k][j] != arr[i][j]){
                        break;
                    }
                    l++;
                }
                if(i-1 < l || N-(i+l)+1 < l){
                    continue;
                }
                char t = arr[i-1][j], m = arr[i][j], bo = arr[i+l][j];
                int cnt = 0;
                for(; j<=M; j++){
                    bool b = 1;
                    for(int k = i; k<i+l; k++){
                        if(arr[k][j] != m){
                            b = 0;
                            break;
                        }
                    }
                    for(int k = i-1; k>=i-l; k--){
                        if(arr[k][j] != t){
                            b = 0;
                            break;
                        }
                    }
                    for(int k = i+l; k<=i+l+l-1; k++){
                        if(arr[k][j] != bo){
                            b = 0;
                            break;
                        }
                    }
                    if(!b && cnt){
                        j--;
                        break;
                    }
                    if(!b){
                        break;
                    }
                    cnt++;
                    ans += cnt;
                }
            }
        }
    }
    cout << ans << endl;
}