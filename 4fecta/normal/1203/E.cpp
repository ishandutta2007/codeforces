#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    cin.tie(0);
    bool v[200000]; memset(v, false, sizeof(v)); v[0] = true;
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int w = a[i];
            if (!v[w - 1]) {
                v[w - 1] = true;
                cnt++;
            } else if (!v[w]) {
                v[w] = true;
                cnt++;
            } else if (!v[w + 1]) {
                v[w + 1] = true;
                cnt++;
            }
        }
        printf("%d\n", cnt);
    return 0;
}