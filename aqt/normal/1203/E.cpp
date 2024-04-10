#include <bits/stdc++.h>

using namespace std;

int N, M = 150001;
int arr[150005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        arr[n]++;
    }
    for(int i = 1; i<=M; i++){
        if(arr[i] >= 1 && arr[i-1] == 0 && i != 1){
            arr[i-1]++;
            arr[i]--;
        }
        if(arr[i] >= 2){
            arr[i]--;
            arr[i+1]++;
        }
    }
    int n = 0;
    for(int i = 1; i<=M; i++){
        if(arr[i]){
            n++;
        }
    }
    cout << n << endl;
}