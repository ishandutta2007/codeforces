#include <bits/stdc++.h>

using namespace std;

int N;
int arr[3][101];
int cst[101];

int main(){
    cin >> N;
    for(int i =1 ; i<=N; i++){
        cin >> arr[0][i] >> arr[1][i] >> arr[2][i] >> cst[i];
    }
    cst[0] = INT_MAX;
    int ans = 0;
    for(int i = 1; i<=N; i++){
        bool b = 0;
        for(int j = 1; j<=N; j++){
            bool t = 1;
            for(int k = 0; k<3; k++){
                if(arr[k][j] <= arr[k][i]){
                    t = 0;
                }
            }
            b |= t;
        }
        if(!b){
            ans = cst[ans] > cst[i] ? i : ans;
        }
    }
    cout << ans << endl;
}