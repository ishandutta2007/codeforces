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
    int x, y;
    pii a, b;
    a.ff = 0;
    a.sc = 0;
    b.ff = 0;
    b.sc = 0;
    cin >> x >> y;
    if(x*1ll*y > 0){
        a.sc = x+y;
        b.ff = x+y;
    }
    else {
        a.sc = y-x;
        b.ff = x-y;
    }
    if(a.ff > b.ff) {
        cout << b.ff << " " << b.sc << " " << a.ff << " " << a.sc;
    }
    else cout << a.ff << " " << a.sc << " " << b.ff << " " << b.sc;
    return 0;
}