#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N+1);
    if(arr[N] == 0 || (N >= 2 && arr[2] == 0)){
        cout << "cslnb" << endl;
        return 0;
    }
    bool secondturn = 0;
    for(int t = 0; t<2; t++){
        for(int i = 1; i<N; i++){
            if(arr[i] == arr[i+1]){
                if(!secondturn){
                    secondturn = 1;
                    arr[i]--;
                }
                else{
                    cout << "cslnb" << endl;
                    return 0;
                }
            }
        }
    }
    long long sum = 0;
    for(int i = 1; i<=N; i++){
        sum += arr[i] - (i-1);
    }
    string ans = (sum%2^secondturn ? "sjfnb" : "cslnb");
    cout << ans << endl;
}