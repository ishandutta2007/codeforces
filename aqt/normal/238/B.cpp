#include <bits/stdc++.h>

using namespace std;

int N, H;
pair<int, int> arr[100005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> H;
    if(N == 2){
        cout << 0 << "\n";
        cout << 1 << " " << 1;
        return 0;
    }
    for(int i= 1; i<=N; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr+1, arr+1+N);
    int opt1 = arr[N].first+arr[N-1].first-arr[2].first-arr[1].first;
    int opt2 = max(arr[1].first+H, arr[N-1].first)+arr[N].first
    -min(arr[2].first+arr[1].first+H, arr[2].first+arr[3].first);
    if(opt1 < opt2){
        cout << opt1 << "\n";
        for(int i = 1; i<=N; i++){
            cout << 1 << " ";
        }
    }
    else{
        cout << opt2 << "\n";
        for(int i = 1; i<=N; i++){
            if(arr[1].second == i){
                cout << 1 << " ";
            }
            else{
                cout << 2 << " ";
            }
        }
    }
}