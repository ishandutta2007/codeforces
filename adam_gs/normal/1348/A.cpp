#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a = 2;
        int sum=0;
        for (int i = 0; i < n/2-1; ++i) {
            sum+=a;
            a*=2;
        }
        for (int i = 0; i < n/2; ++i) {
            sum-=a;
            a*=2;
        }
        sum+=a;
        cout << sum << '\n';
    }
}