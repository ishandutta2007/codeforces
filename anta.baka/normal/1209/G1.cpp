#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <assert.h>
#include <set>
#include <cstdio>
#include <cstring>
#include <queue>
#include <random>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using vi = vector<int>; using pii = pair<int, int>; using ld = long double;
const int N = 3e5;
int a[N], dp[N], nm[N];
bool used[N];
int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //ifstream cin("in.txt");
    int n, q, rs = 0, pos = -1;
    cin >> n >> q;
    vector<int> mask;
    for(int i = 0; i < N; i++)
        dp[i] = -1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        used[i] = (dp[a[i]] == -1);
       // cout << used[i] << " ";
        nm[a[i]]++; dp[a[i]] = i;
    }
    for(int i = 0; i < n; i++) {
        // cout << pos << " ";
        if(used[i] && pos >= i) {
            pos = max(dp[a[i]], pos);
            mask.pb(nm[a[i]]);
            continue;
        }
        else if(used[i] && pos < i) {
            if(mask.size()) {
                int mx = mask[0];
                for(int i = 0; i < mask.size(); i++) {
                    rs += mask[i];
                    mx = max(mask[i], mx);
                }
                rs -= mx;
            }
            mask.clear();
            pos = max(dp[a[i]], pos);
            mask.pb(nm[a[i]]);
          //  cout << i << " " << rs << "\n";
        }
    }
    // cout << "\n";
    if(mask.size()) {
        int mx = mask[0];
        for(int i = 0; i < mask.size(); i++) {
            rs += mask[i];
            mx = max(mask[i], mx);
        }
        rs -= mx;
    }
    cout << rs << "\n";
}