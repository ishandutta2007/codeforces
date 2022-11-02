#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define sc second
#define pii pair<int,int>
#define pis pair<int, string>
#define psi pair<string, int>
using namespace std;
int main () {
    int n, a[10], b[10];
    for(int i = 0; i<9; i++){
        a[i] = 0;
        b[i] = 0;
    }
    cin >> n;
    for(int i = 0; i<n; i++){
        int l, r;
        cin >> l >> r;
        a[l]++;
        b[r]++;
    }
    vector < int > v;
    for(int i = 0; i<2; i++){
        for(int j = 0; j<2; j++)
            v.pb(a[i] + b[j]);
    }
    sort(v.begin(), v.end());
    cout << v[0];
    return 0;
}