#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A.rbegin(), A.rend());
    vector<string> res(N + 1, string(N, '0'));
    int cur = 0;
    for (int i = 0; i < N; i++) {
        int p = A[i].second;
        int v = A[i].first;
        int st = i + 1;
        for (int j = st; j <= N; j++) {
            res[j][p] = '1';
            v--;
            if(v == 0)break;
        }
        st-=2;
        while(v){
            res[st][p] = '1';
            v--;
            st--;
        }
    }
    vector<string> res2;
    
    for(int i = N;i>=0;i--){
        
        if(res[i] != string(N , '0')){
            res2.push_back(res[i]);
        }
    }
    cout << res2.size()<<endl;
    for(int i=0;i<res2.size();i++){
        cout << res2[i]<<endl;
    }
    
}