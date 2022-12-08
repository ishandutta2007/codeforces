#include <bits/stdc++.h>
#define ll long long
#define pl pair<ll,ll>
#define pi pair<int,int>
#define f first
#define s second
#define vi vector<int>
#define vl vector<ll>
#define ld long double

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int d = n / m;
        if(n%m == 0 && false) {
            for(int i = 0; i < k; i ++) {
                int idx = 1;
                for(int mi = 0; mi < m; mi ++) {
                    cout << d << " ";
                    for(int j = 0; j < d; j ++) {
                        cout << (idx++) << " ";
                    }
                    cout << "\n";
                }
            }
        }
        int b = n - d * m;
        int af = b * (d+1);
        int kidx = 0;
        for(int i = 0; i < k; i ++) {
            vector<vector<int>> tables(m);
            int idx = 0;
            for(int j = 0; j < af; j ++) {
                if(tables[idx].size() > d) {
                    idx ++;
                }
                tables[idx].push_back(kidx);
                kidx ++;
                kidx %= n;
            }
            for(int j = af; j < n; j ++) {
                if(tables[idx].size() >= d) {
                    idx ++;
                }
                tables[idx].push_back((kidx+j-af)%n);
            }
            for(int mi = 0; mi < m; mi ++) {
                cout << tables[mi].size() << " ";
                for(int p : tables[mi]) {
                    cout << (p+1) << " ";
                }
                cout << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}