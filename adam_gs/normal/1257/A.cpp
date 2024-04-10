#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, a, b;
        cin >> n >> x >> a >> b;
        int p=min(a,b);
        b=max(a, b);
        a=p;
        a-=min(a-1, x);
        x-=min(p-1, x);
        b+=min(n-b, x);
        cout << b-a << '\n';
    }
}