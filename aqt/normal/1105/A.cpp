#include <bits/stdc++.h>

using namespace std;

int arr[1001];

int main(){
    int N;
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    int ans = 0, cst = INT_MAX;
    for(int k = 1; k<=100; k++){
        int crnt = 0;
        for(int i = 1; i<=N; i++){
            crnt += min(abs(arr[i]-k-1), min(abs(arr[i]-k+1), abs(arr[i]-k)));
        }
        if(crnt < cst){
            ans = k;
            cst = crnt;
        }
    }
    cout << ans << " " << cst << endl;
}