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
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    long long a, b, c, d, x, y, z, t;
    cin >> a >> b >> c >> d;
    x = a*d;
    y = -a*c+a*d+b*c;
    double s = (x*1.0)/y;
    printf("%.15f", s);
    return 0;
}