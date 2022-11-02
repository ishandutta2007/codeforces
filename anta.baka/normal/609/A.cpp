#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a,a+n,greater<int>());
    int last = 0;
    while(m > 0) {
        m -= a[last];
        last++;
    }
    cout << last;
}