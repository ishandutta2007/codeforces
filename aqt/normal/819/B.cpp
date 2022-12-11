#include <bits/stdc++.h>

using namespace std;

int N;
int arr[1000005];
priority_queue<int, vector<int>, greater<int>>pq;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    long long crnt = 0, add = 0, sub = 0;
    for(int i =1; i<=N; i++){
        cin >> arr[i];
        crnt += abs(i - arr[i]);
        if(arr[i] > i){
            add++;
        }
        else{
            sub++;
        }
        //cout << (i-arr[i]+1 <= 0 ? i+N-arr[i]+1 : i-arr[i]+1) << endl;
        pq.push(i-arr[i]+1 <= 0 ? i+N-arr[i]+1 : i-arr[i]+1);
    }
    long long ans = LLONG_MAX/2, idx = 0;
    for(int i = 1; i<=N; i++){
        //cout << crnt << endl;
        if(ans > crnt){
            idx = i-1;
            ans = crnt;
        }
        while(pq.size() && pq.top() == i){
            pq.pop();
            sub--;
            add++;
        }
        crnt -= arr[i] - 1;
        crnt += N - arr[i];
        sub++;
        add--;
        crnt += add - sub + 1;
    }
    cout << ans << " " << (N-idx)%N << endl;
}