#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = (int)2e5 + 10;
int n;
int a[maxn];
int p[maxn];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        p[a[i]] = i;
    }
    int mi = 1;
    for(int i = 1; i <= n; ) {
        while(p[mi] < i) mi++;
        if(p[mi] == i) {
            i++;
            continue;
        }
        int en = p[mi];
        for(int j = en; j > i; j--) {
            swap(a[j], a[j-1]);
            p[a[j]] = j;
            p[a[j-1]] = j-1;
        }
        i = en;
    }

    for(int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i == n];
    }
}
int main() {
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}