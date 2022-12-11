#include <bits/stdc++.h>

using namespace std;

int N, M;
priority_queue<int, vector<int>, greater<int>> pq;
int arr[200005];
vector<int> pos[200005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 1; i<=M; i++){
        cin >> arr[i];
        pos[arr[i]].push_back(i);
    }
    long long ans = 0;
    for(int i = 2; i<=M; i++){
        ans += abs(arr[i]-arr[i-1]);
    }
    for(int i =1 ; i<=N; i++){
        long long s = 0;
        while(pq.size() && pq.top() == i){
            pq.pop();
        }
        for(int p : pos[i]){
            if(p < M){
                s -= abs(arr[p]-arr[p+1]);
                if(arr[p+1] > i){
                    s += arr[p+1]-1;
                }
                else if(arr[p+1] < i){
                    s += arr[p+1];
                }
            }
            if(p > 1){
                s -= abs(arr[p]-arr[p-1]);
                if(arr[p-1] > i){
                    s += arr[p-1]-1;
                }
                else if(arr[p-1] < i){
                    s += arr[p-1];
                }
            }
        }
        cout << (ans + s - pq.size()) << " ";
        for(int p : pos[i]){
            if(p < M){
                if(arr[p+1] > i){
                    pq.push(arr[p+1]);
                }
            }
            if(p > 1){
                if(arr[p-1] > i){
                    pq.push(arr[p-1]);
                }
            }
        }
    }
}