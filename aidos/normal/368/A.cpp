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
    int n, a[111], b[111], m, d;
    b[0] = 0;
    cin >> n >> d;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
    cin >> m;
    sort(a+1, a+n+1);
    for(int i = 1; i<=n; i++){
        b[i] = b[i-1] + a[i];
    }
    int ans = b[min(n,m)];
    if(m>n) ans-=(m-n)*d;
    cout << ans;
    return 0;
}