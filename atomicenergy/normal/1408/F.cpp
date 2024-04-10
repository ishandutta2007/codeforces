
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

    int n;
    cin >> n;
    if (n <= 2) {
        cout << 0 << endl;
        return 0;
    }
    vector<pair<int, int> > ans;
    int i = 1;
    while (2 * i <= n) i *= 2;

    for (int k = 1; k < i; k*=2) {
        for (int j = 0; j < i; j++) {
            if ((j ^ k) > j) ans.push_back({ j, j ^ k });
        }
    }
    for (int k = 1; k < i; k *= 2) {
        for (int j = 0; j < i; j++) {
            if ((j ^ k) > j) ans.push_back({ n-1-j, n-1-(j ^ k) });
        }
    }
    for (int k = 0; k < n - i; k++) {
        ans.push_back({ k, n - 1-k });
    }
    cout << ans.size() << endl;

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first+1 << " " << ans[i].second+1;
        cout << endl;
    }
    


}