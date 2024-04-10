#include <bits/stdc++.h>

using namespace std;

int arr[1000005];
int N, K;

void solve(int l, int r){
    if(r-l == 1){
        return;
    }
    if(!K){
        return;
    }
    int mid = (l+r)>>1;
    swap(arr[mid-1], arr[mid]);
    K-=2;
    solve(l, mid);
    solve(mid, r);
}

int main(){
    cin >> N >> K;
    if(K%2 == 0){
        cout << -1 << endl;
        return 0;
    }
    K--;
    for(int i = 0; i<N; i++){
        arr[i] = i+1;
    }
    solve(0, N);
    if(K){
        cout << -1 << endl;
    }
    else{
        for(int i=0; i<N; i++){
            cout << arr[i] << " ";
        }
    }
}