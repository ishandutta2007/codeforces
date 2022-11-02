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
    int n, mi = 1 << 30, mx = 0, l[111000], r[111000];
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> l[i] >> r[i];
        mi = min(l[i], mi);
        mx = max(r[i], mx);
    }
    for(int i = 0; i<n; i++){
        if(l[i] == mi && r[i] == mx) {
            cout << i+1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}