#include <bits/stdc++.h>

using namespace std;
string s;
int n;
int a[100100];
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int l = min_element(a, a + n) - a;
        int r = max_element(a, a + n) - a;
        if(l > r) swap(l, r);
        cout << min({n - l, r+1, n - (r-l-1)}) << "\n";
    }
}