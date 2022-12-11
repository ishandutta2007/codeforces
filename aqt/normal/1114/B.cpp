#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int arr[200005];
priority_queue<pair<int, int>> pq;
bool tkn[200005];

int main(){
    cin >> N >> M >> K;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        pq.push({arr[i], i});
    }
    int cnt = M*K;
    long long tot = 0;
    while(cnt){
            tot += pq.top().first;
        tkn[pq.top().second] = 1;
        pq.pop();
        cnt--;
    }
    printf("%lld\n", tot);
    cnt = 0;
    for(int i = 1; i<=N; i++){
        if(tkn[i]){
            cnt++;
            if(!(cnt%M) && cnt < K*M && cnt > 0){
                printf("%d ", i);
            }
        }
    }
}