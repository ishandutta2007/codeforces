#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <time.h>
#include <map>
#include <vector>
#define ll long long
#define pii pair <ll, int>
#define mp make_pair

using namespace std;

const int maxn = (int)1e5 + 10;
int l[maxn], r[maxn];

int main() {
    int n;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &l[i], &r[i]);
    }
    
    sort(l, l + n);
    sort(r, r + n);
    
    ll ans = 0;
    
    for (int i = 0; i < n; i++) {
        ans += max(l[i], r[i]);
    }
    
    cout << ans + n << endl;
    
    return 0;
}