#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int N, P, K;
        cin >> N >> P >> K;
        vector<long long> v(N);
        vector<long long> m(K);
        for(int i = 0; i<N; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        for(int i = 1; i<K-1; i++){
            v[i] += v[i-1];
        }
        int ans = 0;
        //cout << "\n";
        for(int i = 0; i<N; i++){
            m[i%K] += v[i];
            //cout << m[i%K] << " ";
            if(m[i%K] <= P){
                ans = i+1;
            }
        }
        cout << ans << "\n";
    }
}