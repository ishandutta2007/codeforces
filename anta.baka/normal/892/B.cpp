#include <bits/stdc++.h>
using namespace std;

int n, a[1000000], ret, s;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a[max(0, i - x)]++; a[i]--;
    }
    for(int i = 0; i < n; i++) {
        s += a[i];
        if(s == 0) ret++;
    }
    cout << ret;
}