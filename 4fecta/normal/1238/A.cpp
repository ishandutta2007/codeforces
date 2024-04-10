#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;
    for (; q > 0; q--) {
        long long a, b;
        cin >> a >> b;
        if (a - b > 1) printf("YES\n");
        else printf("NO\n");
    }
}