#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[2000];

bool can(int d) {
    vector<int> f(n, n-1);
    f[0] = n - 1;
    for(int i = 1; i < n; i++)
        for(int j = 0; j < i; j++)
            if(abs(a[i]-a[j]) <= 1LL*(i-j)*d)
                f[i] = min(f[i], f[j] - 1);
    int res = n-1;
    for(int i = 0; i < n; i++)
        res = min(res, f[i]);
    return res <= k;
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    long long bl = 0, br = 2000000000;
    while(bl < br) {
        long long bm = (bl + br)>>1;
        if(can(bm))
            br = bm;
        else
            bl = bm + 1;
    }
    cout << bl;
}