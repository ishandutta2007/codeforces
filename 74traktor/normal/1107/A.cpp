#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    for (int i = 1; i <= q; ++i){
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n == 2){
            if (s[0] >= s[1]){
                cout << "NO" << endl;
                continue;
            }
        }
        cout << "YES" << endl;
        cout << 2 << endl;
        cout << s[0] << " ";
        for (int j = 1; j < n; ++j) cout << s[j];
        cout << endl;
    }
    return 0;
}