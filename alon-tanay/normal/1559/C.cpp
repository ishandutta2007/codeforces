#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define ld long double
#define pi pair<int,int>
#define pl pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define f first
#define s second
#define vvi vector<vi>
#define vvl vector<vl>

using namespace std;
using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int x;
        vector<int> go(n+2);
        go[n+1] = 1;
        for(int i = 1; i <= n; i ++) {
            cin >> go[i];
        }
        bool pass = false;
        for(int i = 1; i <= n; i ++) {
            if(go[i] == 0 && go[i+1] == 1) {
                pass = true;
                for(int j = 1; j <= i; j ++) {
                    cout << j << " ";
                }
                cout << n+1 << " ";
                for(int j = i + 1; j <= n; j ++) {
                    cout << j << " ";
                }
                cout << "\n";
                break;
            }
        }
        if(pass) { continue;}
        if(go[1] == 1) {
            cout << n + 1 << " ";
            for(int j = 1; j <= n; j ++) {
                cout << j << " ";
            }
            cout << "\n";
            continue;
        }
        if(pass) { continue;}
        cout << "-1\n";
    }
    return 0;
}