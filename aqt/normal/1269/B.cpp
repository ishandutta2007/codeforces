#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[2005], brr[2005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    for(int i = 1; i<=N; i++){
        cin >> brr[i];
    }
    sort(arr+1, arr+1+N);
    sort(brr+1, brr+1+N);
    int ans = INT_MAX;
    for(int i = 1; i<=N; i++){
        int t = arr[1];
        for(int j = 1; j<N; j++){
            arr[j] = arr[j+1];
        }
        arr[N] = t;
        int dif = brr[1] - arr[1];
        if(dif < 0){
            dif += M;
        }
        bool b = 1;
        for(int k = 1; k<=N; k++){
            int d = brr[k] - arr[k];
            if(brr[k] - arr[k] < 0){
                d += M;
            }
            b &= d == dif;
        }
        if(b){
            ans = min(ans, dif);
        }
    }
    cout << ans << endl;
}