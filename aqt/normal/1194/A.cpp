#include <bits/stdc++.h>

using namespace std;

long long arr[1000001];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for(int i = 1; i<=1000000; i++){
        arr[i] = arr[i-1] + i;
    }
    while(T--){
        int n, x;
        cin >> n >> x;
        cout << 2*x << "\n";
    }
}