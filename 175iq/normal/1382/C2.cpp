#include <bits/stdc++.h>
using namespace std;
 
int t, n;
string a, b;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> a >> b;
        vector<int> ops1, ops2;
        a += '0'; b += '0';
        for(int i = 1; i <= n; i++) {
            if(a[i] != a[i - 1]) ops1.push_back(i);
            if(b[i] != b[i - 1]) ops2.push_back(i);
        }
        ops1.insert(ops1.end(), ops2.rbegin(), ops2.rend());
        cout << ops1.size();
        for(int x : ops1) {
            cout << ' ' << x;
        }
        cout << '\n';
    }
}