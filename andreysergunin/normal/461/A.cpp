#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a));
    long long ans = 0;
    for (long long i = 0; i < n; ++i)
        ans += a[i] * (i + 2);
    ans -= a[n - 1];
    cout << ans << endl;
}