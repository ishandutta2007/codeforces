#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int cnt = 0;
    for(int i = 2; i<=N; i++){
        if(arr[i]){
            continue;
        }
        arr[i] = ++cnt;
        for(int j = i; j<=N; j+=i){
            arr[j] = cnt;
        }
    }
    for(int i = 2; i<=N; i++){
        cout << arr[i] << " ";
    }
}