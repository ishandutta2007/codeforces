#include <bits/stdc++.h>

using namespace std;

int N;
int ans[100005];
long double arr[100005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        ans[i] = floor(arr[i]);
    }
    long long s = 0;
    for(int i = 1; i<=N; i++){
        s += ans[i];
    }
    for(int i = 1; i<=N && s; i++){
        if(arr[i] - ans[i] <= 1e-9){
            continue;
        }
        s -= ans[i];
        ans[i] = (int) (ceil(arr[i]));
        s += ans[i];
    }
    for(int i= 1; i<=N; i++){
        cout << ans[i] << "\n";
    }
}