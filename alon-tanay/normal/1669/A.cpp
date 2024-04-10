#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define MOD 998244353
#define pi pair<int,int>
#define pl pair<ll,ll>
#define f first
#define s second

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int d = 1;
        if(n <= 1399) {
            d = 4;
        } else if(n <= 1599) {
            d = 3;
        } else if(n <= 1899) {
            d = 2;
        }
        cout << "Division " << d << "\n";
    }
    return 0;
}