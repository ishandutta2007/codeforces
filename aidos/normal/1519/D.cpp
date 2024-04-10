#include <bits/stdc++.h>

using namespace std;
string s;
int n;
long long a[5050];
long long b[5050];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    long long all = 0;
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        all += a[i] * b[i];
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        int l=i;
        int r=i+1;
        long long cur = 0;
        while(l >= 1 && r <= n) {
            cur += a[l] * b[r] + a[r] * b[l] - a[l] * b[l] - a[r] * b[r];
            ans = max(ans, cur);
            l--;
            r++;
        }
        l=i-1;
        r=i+1;
        cur = 0;
        while(l >= 1 && r <= n) {
            cur += a[l] * b[r] + a[r] * b[l] - a[l] * b[l] - a[r] * b[r];
            ans = max(ans, cur);
            l--;
            r++;
        }
    }
    cout << all+ans << "\n";

}