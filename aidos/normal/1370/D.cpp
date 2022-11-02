#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = (int)2e5 + 10;
int n, k;
int a[maxn];
int get(int x) {
    int c0 = 0, c1 = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] <= x) {
            c0++;
            c1++;
        } else {
            if(c0 % 2 == 1) c0++;
            if(c1 % 2 == 0) c1++;
        }
    }
    return max(c0, c1);
}
int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, r = 1e9;
    int res = -1;
    while(l <= r) {
        int mid = (l + r)/2;
        if(get(mid) >= k) {
            res = mid;
            r = mid - 1;
        }else {
            l = mid + 1;
        }
    }
    cout << res << "\n";
}