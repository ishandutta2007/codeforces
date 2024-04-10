#include <bits/stdc++.h>

using namespace std;

int out[100005];
int a[100005];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int uk = 1;
    for (int i = 1; i <= n; i += 2){
        if (n % 2 == 1 && i == n){
            out[uk] = a[i];
            break;
        }
        out[uk] = a[i], out[n - uk + 1] = a[i + 1];
        uk++;
    }
    for (int i = 1; i <= n; ++i) cout << out[i] << " ";
    return 0;
}