#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M;
    cin >> M >> N;
    vector<int> v;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());
    M--;
    N--;
    int ans = INT_MAX;
    for(int i = M; i<=N; i++){
        ans = min(ans, v[i]-v[i-M]);
    }
    cout << ans << endl;
}