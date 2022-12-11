#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> arr[200005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr+1, arr+1+N);
    int idx1 = 0, idx2 = arr[2].second, idx3 = arr[1].second;
    int lst = 2;
    for(int i = 3; i<=N; i++){
        if(arr[i].first - arr[lst].first != arr[2].first - arr[1].first){
            if(idx1){
                idx1 = -1;
                break;
            }
            idx1 = arr[i].second;
        }
        else{
            lst = i;
        }
    }
    if(!idx1){
        idx1 = 1;
    }
    lst = 3;
    for(int i = 4; i<=N; i++){
        if(arr[i].first - arr[lst].first != arr[3].first - arr[1].first){
            idx2 = -1;
            break;
        }
        else{
            lst = i;
        }
    }
    lst = 3;
    for(int i = 4; i<=N; i++){
        if(arr[i].first - arr[lst].first != arr[3].first - arr[2].first){
            idx3 = -1;
            break;
        }
        else{
            lst = i;
        }
    }
    cout << max(max(idx1, idx2), idx3) << endl;
}