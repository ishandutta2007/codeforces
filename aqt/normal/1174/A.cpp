#include <bits/stdc++.h>

using namespace std;

int N;
int arr[2005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    bool k = 1;
    N = 2*N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        if(i != 1 && arr[i] != arr[i-1]){
            k = 0;
        }
    }
    if(k){
        cout << -1 << endl;
        return 0;
    }
    sort(arr, arr+1+N);
    for(int i = 1; i<=N; i++){
        cout << arr[i] << " ";
    }
}