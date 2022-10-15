#include <bits/stdc++.h>

using namespace std;

int q, n, m;
int main() {
    cin >> q;
    for (; q > 0; q--) {
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> m;
            //printf("%d ", m);
            sum += m;
        }
        printf("%.0f\n", ceil((double) ((double) (sum) / (double) (n))));
    }
}