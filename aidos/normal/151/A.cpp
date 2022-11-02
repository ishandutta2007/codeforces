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
    int n, k, l, c, d, p, nl, np, ans = 0;
    scanf("%d%d%d%d%d%d%d%d", &n, &k, &l, &c, &d, &p, &nl, &np);
    k*=l;
    c*=d;
    while(n<=c && nl*1ll*n <= k && np*1ll*n <= p){
        c-=n;
        k-=nl*1ll*n;
        p-=np*1ll*n;
        ans++;
    }
    cout << ans;
    return 0;
}