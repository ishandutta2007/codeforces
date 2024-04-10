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
    int l, g, v, r, d, t;
    cin >> l >> d >> v >> g >> r;
    double x;
    t = d%(v*(g+r));
    if(t<g*v) x = 1.0*l/v;
    else x = (l-t+v*g+v*r)*1.0/v;
    printf("%.12f", x);
    return 0;
}