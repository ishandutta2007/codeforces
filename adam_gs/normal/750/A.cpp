#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    k=240-k;
    int s=0;
    int r=0;
    while (s<=k) {
        ++r;
        s+=r*5;
    }
    cout << min(r-1, n);
}