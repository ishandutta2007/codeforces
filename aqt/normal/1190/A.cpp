#include <bits/stdc++.h>

using namespace std;

long long N, M, K;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    long long cnt = 0;
    vector<long long> v;
    for(int i = 1; i<=M; i++){
        long long n;
        cin >> n;
        n--;
        v.push_back(n);
    }
    int idx = 0;
    int ans = 0;
    while(idx < v.size()){
        int x = idx;
        long long crnt = (v[idx]-idx)/K*K+K-1;
        ans++;
        while(idx < v.size() && v[idx]-x <= crnt){
            idx++;
        }
    }
    cout << ans << endl;
}