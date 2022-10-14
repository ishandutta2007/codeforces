#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <memory.h>
#include <cstdlib>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair                  
#define F first
#define S second
#define scf scanf
#define prf printf

typedef long double ld;
typedef long long ll;

int main() {
    int n, k;
    vector < int > res;
    vector < pair < int, int > > v;
    scf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        int x;
        scf("%d", &x);
        v.pb(mp(x, i + 1));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        if (k - v[i].F < 0) break;
        else {
            res.pb(v[i].S);
            k -= v[i].F;
        }
    prf("%d\n", res.size());
    for (int i = 0; i < res.size(); i++)
        prf("%d ", res[i]); 
    return 0;
}