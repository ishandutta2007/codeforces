#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define ppi pair<int,pi>
#define MOD 1000000007

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >>t;
    while(t--) {
        ll n, s;
        cin >> n >> s;
        cout << s / (n * n) << "\n";
    }
    return 0;
}