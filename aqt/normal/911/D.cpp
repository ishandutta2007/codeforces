#include <bits/stdc++.h>

using namespace std;

int N, Q;
int arr[1505];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    bool ans = 0;
    for(int i =1 ; i<=N; i++){
        cin >> arr[i];
        for(int j= i-1; j>0; j--){
            ans ^= (arr[i] < arr[j]);
        }
    }
    cin >> Q;
    while(Q--){
        int l, r;
        cin >> l >> r;
        int k = r-l+1;
        k = k*(k-1)/2;
        ans ^= (k&1);
        if(ans){
            cout << "odd" << "\n";
        }
        else{
            cout << "even" << "\n";
        }
    }
}