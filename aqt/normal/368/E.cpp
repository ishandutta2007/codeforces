#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    priority_queue<int> pq;
    for(int i = 1; i<=M; i++){
        int q, w;
        cin >> q >> w;
        pq.push(w);
    }
    int n = 0;
    while(true){
        if(n%2){
            if(n*(n-1)/2+1 > N){
                break;
            }
            else{
                n++;
            }
        }
        else{
            if(n*(n-1)/2+(n-2)/2+1 > N){
                break;
            }
            else{
                n++;
            }
        }
    }
    n--;
    long long ans = 0;
    while(n-- && pq.size()){
        ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;
}