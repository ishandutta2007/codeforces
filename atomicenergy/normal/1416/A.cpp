
using namespace std;

#define visual

#ifdef visual
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>
#include <math.h>
#include <string>
#include <ctime>
#endif
#ifndef visual
#include <bits/stdc++.h>
#endif

typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tests;
    cin >> tests;
    for (int casenum = 1; casenum <= tests; casenum++) {
        int n;
        cin >> n;

        vector<int> v;
        vector<vector<int> > freqs(n + 1);
        for (int i = 1; i <= n; i++) {
            freqs[i].push_back(-1);
        }
        
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v.push_back(x);
            freqs[x].push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            freqs[i].push_back(n);
        }
        vector<int> answer(n + 5, n + 5);
        for (int i = 1; i <= n; i++) {
            int mxdif = 0;
            for (int j = 1; j < freqs[i].size(); j++) {
                mxdif = max(mxdif, freqs[i][j] - freqs[i][j - 1]);
            }

            answer[mxdif] = min(answer[mxdif], i);
        }
        int cur = n + 5;
        for (int i = 1; i <= n; i++) {
            cur = min(cur, answer[i]);
            if (cur == n + 5) cout << -1 << " ";
            else cout << cur << " ";
        }
        cout << endl;

    }


}