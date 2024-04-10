#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 3e5 + 123;
const int mod = 1e9 + 9;
string s;
int n;
int a[maxn];
void solve() {

    cin >> n;
    for(int i=0; i < n; i++) {
        cin >> a[i];
    }
    int r = n-1;
    int l = 0;
    for(int i = 0; i < n; i++) {
        if(i % 2) {
            cout << a[r] << " ";
            r--;
        } else {
            cout << a[l] << " ";
            l++;
        }
    }
    cout << "\n";

}
int main() {
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }

    return 0;
}