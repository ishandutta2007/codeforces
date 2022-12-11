#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[100005];
deque<int> lft, rht;

void shift(){
    rht.push_front(0);
    int k = rht.back();
    rht.pop_back();
    rht.back() += k;
    lft.push_back(0);
    k = lft.front();
    lft.pop_front();
    lft.front() += k;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    if(N == 1){
        if(M >= 1){
            cout << 0;
        }
        else{
            cout << 1;
        }
        return 0;
    }
    long long ans = -1LL*N*(N-1)-N;
    for(int i = 1; i<=N; i++){
        rht.push_back(1);
        lft.push_back(1);
    }
    for(int i = 1; i<=M; i++){
        shift();
        cin >> arr[i];
        if(arr[i] != 1){
            rht[arr[i]-2] += rht[arr[i]-1];
            rht[arr[i]-1] = 0;
        }
        if(arr[i] != N){
            lft[arr[i]] += lft[arr[i]-1];
            lft[arr[i]-1] = 0;
        }
    }
    shift();
    for(int i = 1; i<=N; i++){
        ans += 1LL*lft[i-1]*(N-i+1);
        ans += 1LL*rht[i-1]*i;
    }
    cout << ans << endl;
}