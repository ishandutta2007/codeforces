#include <bits/stdc++.h>

using namespace std;

pair<int, int> arr[300005];

int main(){
    int N;
    cin >> N;
    for(int i =1 ; i<=N; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr+1, arr+1+N);
    int lft = 0, rht = 1e9;
    for(int i = 1; i<N; i++){
        lft = max(arr[i].first, lft);
        rht = min(arr[i].second, rht);
    }
    int ans = rht-lft;
    for(int i= 1; i<=N; i++){
        swap(arr[i].first, arr[i].second);
    }
    sort(arr+1, arr+1+N);
    lft = 0;
    rht = 1e9;
    for(int i = 2; i<=N; i++){
        lft = max(arr[i].second, lft);
        rht = min(arr[i].first, rht);
    }
    cout << max(max(0, rht-lft), ans) << endl;
}