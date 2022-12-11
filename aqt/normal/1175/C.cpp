#include <bits/stdc++.h>

using namespace std;

int T;

int main(){
    cin >> T;
    while(T--){
        int N, K;
        cin >> N >>K;
        K++;
        vector<int> v;
        for(int i = 1; i<=N; i++){
            int n;
            cin >> n;
            v.push_back(n);
        }
        sort(v.begin(), v.end());
        int len = INT_MAX, ans = 0;
        for(int i = 0; i<N-K+1; i++){
            if(v[i+K-1]-v[i] <= len){
                len = v[i+K-1] - v[i];
                ans = (v[i]+v[i+K-1])>>1;
            }
        }
        cout << ans << "\n";
    }
}