#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[200005], ans[200005];
deque<int> dq;

int main(){
    cin >> N >> M;
    for(int i =1; i<=N; i++){
        cin >> arr[i];
    }
    for(int i = 1; i<=M; i++){
        int t, n;
        cin >> t >> n;
        while(dq.size() && abs(dq.front()) <= n){
            dq.pop_front();
        }
        if(t == 1){
            dq.push_front(n);
        }
        else{
            dq.push_front(-n);
        }
    }
    sort(arr+1, arr+1+abs(dq.back()));
    int l = 1, r = N;
    for(; r>abs(dq.back()); r--){
        ans[r] = arr[r];
    }
    bool rev = dq.back() > 0;
    dq.pop_back();
    int idx = r;
    dq.push_front(0);
    while(dq.size()){
        while(idx > abs(dq.back())){
            ans[idx--] = rev ? arr[r--] : arr[l++];
        }
        rev = dq.back() > 0;
        dq.pop_back();
    }
    for(int i = 1; i<=N; i++){
        cout << ans[i] << " ";
    }
}