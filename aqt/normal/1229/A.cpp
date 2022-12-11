#include <bits/stdc++.h>

using namespace std;

int N;
long long msk[7005];
long long arr[7005];
bool tkn[7005];

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> msk[i];
    }
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            if((msk[i] == msk[j]) && i != j){
                tkn[i] = 1;
            }
        }
    }
    long long ans = 0;
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            if((msk[i]&msk[j]) == msk[j] && i != j && tkn[i]){
                tkn[j] = 1;
            }
        }
    }
    for(int i =1 ; i<=N; i++){
        ans += arr[i]*tkn[i];
    }
    cout << ans << endl;
}