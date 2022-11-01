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
 
int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int rs = 0;
    for(int i = 0; i < n; i++) {
        int x = 0;
        for(int j = 0; j < i; j++) {
            if(a[i] % a[j] == 0) x++;
        }
        rs += (x == 0);
    }
    cout << rs << "\n";
}