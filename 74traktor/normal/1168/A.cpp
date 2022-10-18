#include <bits/stdc++.h>

using namespace std;

int a[300005];
int b[300005];
int m;

bool check(int imax, int n){
    b[1] = a[1];
    if (a[1] + imax >= m) b[1] = 0;
    for (int i = 2; i <= n; ++i){
        if (a[i] == b[i - 1]){
            b[i] = b[i - 1];
        }
        else if (a[i] > b[i - 1]){
            if ((a[i] + imax) % m >= b[i - 1] && a[i] + imax >= m) b[i] = b[i - 1];
            else b[i] = a[i];
        }
        else{
            if (b[i - 1] - a[i] > imax) return false;
            else b[i] = b[i - 1];
        }
    }
    return true;
}

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int l = -1, r = m - 1;
    while (r - l > 1){
        int mid = (r + l) / 2;
        if (check(mid, n)) r = mid;
        else l = mid;
    }
    cout << r << '\n';
    return 0;
}