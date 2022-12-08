#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define vi vector<int>
#define INF 1073741823

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        string s;
        string m;
        cin >> s;
        cin >> m;
        int n = m.length();
        bool found = false;
        for(int i = 0; i < n; i ++) {
            if(m[i] == 'a') {
                found = true;
                break;
            }
        }
        if(found) {
            if(n == 1) {
                cout << "1\n";
            } else {
                cout << "-1\n";
            }
            continue;
        }
        cout << (1LL<<(ll)(s.length())) << "\n";
    }
    return 0;
}