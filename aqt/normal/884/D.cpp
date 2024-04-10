#include <bits/stdc++.h>

using namespace std;

int N;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        long long n;
        cin >> n;
        pq.push(n);
    }
    if(pq.size()%2 == 0){
        pq.push(0);
    }
    long long ans = 0;
    while(pq.size() > 1){
        long long a, b, c;
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        c = pq.top();
        pq.pop();
        ans += a+b+c;
        pq.push(a+b+c);
    }
    cout << ans << endl;
}