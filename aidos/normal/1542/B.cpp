#include <bits/stdc++.h>

using namespace std;
string s;
int n;
int a[100100];
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        long long n, a, b;
        cin >> n >> a >> b;
        if(b == 1 || n % b == 1) {
            cout << "Yes\n";
            continue;
        }
        if(a == 1) {
            cout << "No\n";
            continue;
        }
        long long x = 1;
        while(x <= n) {
            if((n - x) % b == 0) {
                break;
            }
            x *= a;
        }
        if(x <= n && (n - x) % b == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}