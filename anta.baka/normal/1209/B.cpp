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
bool used[N];
int a[N] , b[N];
int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, rs = 0;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++)
        used[i] = (s[i] == '1');
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    for(int i = 0; i * 2 < N; i++) {
        int cur = 0;
        for(int j = 0; j < n; j++) {
            int x = i - b[j];
            if(x % a[j] == 0 && i + 1 > b[j])
                used[j] ^= 1;
        }
        for(int it = 0; it < n; it++)
            cur += used[it];
        rs = max(cur , rs);
    }
    cout << rs << "\n";
}