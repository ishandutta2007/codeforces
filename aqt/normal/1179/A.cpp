#include <bits/stdc++.h>

using namespace std;

int N, M;
deque<int> dq;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    int maxi = 0, init = 0;
    for(int i =1 ; i<=N; i++){
        int n;
        cin >> n;
        dq.push_back(n);
        maxi = max(n, maxi);
    }
    vector<pair<int, int>> v;
    while(dq.front() != maxi){
        int n = dq.front();
        dq.pop_front();
        int m = dq.front();
        dq.pop_front();
        v.push_back({n, m});
        if(n > m){
            dq.push_front(n);
            dq.push_back(m);
        }
        else{
            dq.push_front(m);
            dq.push_back(n);
        }
        init++;
    }
    while(M--){
        long long n;
        cin >> n;
        n--;
        if(n < init){
            cout << v[n].first << " " << v[n].second << "\n";
        }
        else{
            n -= init;
            n %= (N-1);
            cout << maxi << " " << dq[n+1] << "\n";
        }
    }
}