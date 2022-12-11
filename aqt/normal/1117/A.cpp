#include <bits/stdc++.h>

using namespace std;

int arr[1000005];
int N;

int main(){
    cin >> N;
    int lst = 0, ans = 1, cnt = 0;
    int maxi = 0;
    for(int i =1 ; i<=N; i++){
        cin >> arr[i];
        maxi = max(maxi, arr[i]);
    }
    for(int i=  1; i<=N; i++){
        if(arr[i] == maxi){
            cnt++;
        }
        else{
            cnt = 0;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}