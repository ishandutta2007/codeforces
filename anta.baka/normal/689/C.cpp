#include <bits/stdc++.h>
using namespace std;

long long cnt(long long n) {
    long long res = 0;
    for(long long k=2; ; k++) {
        if(n/(k*k*k) == 0)
            break;
        res += n/(k*k*k);
    }
    return res;
}

int main()
{
    long long m;
    cin >> m;

    long long l = 0, r = 1000000000ll*10000000;
    while(l < r) {
        long long mid = (l + r) / 2;
        if(cnt(mid) >= m)
            r = mid;
        else
            l = mid + 1;
    }

    if(cnt(l) != m) l = -1;
    cout << l;
}