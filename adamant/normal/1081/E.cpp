#include<bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int maxn = 2e5 + 42;

vector<int> divs[maxn];
vector<pair<int, int>> pos[maxn];

int dp[maxn][51];

signed main(){
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1; i < maxn; i++) {
        for(int j = i; j < maxn; j += i) {
            divs[j].push_back(i);
        }
    }
    int n;
    cin >> n;
    int a[n];
    for(int i = 1; i < n; i += 2) {
        cin >> a[i];
    }
    for(int i = 1; i < n; i += 2) {
        for(auto it: divs[a[i]]) {
            int A = it, B = a[i] / it;
            if(A % 2 == B % 2 && A < B) {
                pos[i - 1].push_back({(B - A) / 2, (B + A) / 2});
            }
        }
    }
    int cur = 0;
    for(int i = 0; i < n; i += 2) {
        bool ok = false;
        int mn = 0;
        for(size_t j = 0; j < pos[i].size(); j++) {
            if(pos[i][j].first > cur) {
                if(ok == false || pos[i][j].second < pos[i][mn].second) {
                    mn = j;
                }
                ok = true;
            }
        }
        if(!ok) {
            cout << "No" << endl;
            return 0;
        } else {
            a[i] = pos[i][mn].first * pos[i][mn].first - cur * cur;
            cur = pos[i][mn].second;
        }
    }
    
    cout << "Yes" << endl;
    for(int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}