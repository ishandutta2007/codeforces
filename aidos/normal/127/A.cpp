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
    int n;
    double k, ans = 0;
    pii f, s;
    cin >> n >> k >> f.ff >> f.sc;
    for(int i = 1; i<n; i++){
        cin >> s.ff >> s.sc;
        ans += sqrt(1.0*((s.ff-f.ff) * (s.ff-f.ff) + (s.sc - f.sc) * (s.sc - f.sc)));
        f=s;
    }
    ans *= k;
    ans /= 50.0;
    printf("%.12lf", ans);
    return 0;
}