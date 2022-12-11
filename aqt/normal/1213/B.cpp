#include <bits/stdc++.h>

using namespace std;

int T;
int mn[150005];
int arr[150005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        for(int i = 1; i<=N; i++){
            cin >> arr[i];
        }
        mn[N] = arr[N];
        for(int i = N-1; i; i--){
            mn[i] = min(arr[i], mn[i+1]);
        }
        int cnt = 0;
        for(int i = 1; i<=N; i++){
            if(arr[i] > mn[i]){
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}