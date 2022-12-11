#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[300005];

bool chk(int d){
    int lst = 0;
    for(int i =1 ; i<=N; i++){
        if((lst+M-arr[i])%M <= d){
            continue;
        }
        if(lst > (arr[i]+d)){
            return false;
        }
        lst = arr[i];
    }
    return true;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    int l = 0, r = M-1, ans = 0;
    while(l <= r){
        int mid = l+r>>1;
        if(chk(mid)){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << ans << endl;
}