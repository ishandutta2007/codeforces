#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n, m;
    cin >> n >> m;
    vector<string> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    vector<int> cnt(m, 0);
    for(int j = 1; j < m; j++){
        for(int i = 1; i < n; i++){
            if(A[i - 1][j] == 'X' && A[i][j - 1] == 'X'){
                cnt[j]++;
                break;
            }
        }
        cnt[j] += cnt[j - 1];
    }
    int q, l, r;
    cin >> q;
    while(q--){
        cin >> l >> r;
        if(cnt[l - 1] == cnt[r - 1]) cout << "YES\n";
        else cout << "NO\n";
    }
}