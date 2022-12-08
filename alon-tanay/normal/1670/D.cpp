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
        
        n --;
        n /= 2;
        n ++;
        if(n == 1) {
            cout << "2\n";
            continue;
        } else if(n == 2) {
            cout << "3\n";
            continue;
        }
        int k = sqrt(n/3.0L)-1;
        int res = 3*(k+1);
        int cov = 3 * (k+1) * (k+1);
        int dif = n - cov;
        if(dif == 0) {
            // he
        } else if(dif <= 2*(k+1)) {
            res ++;
        } else if(dif <= 4*(k+1)+1){
            res += 2;
        } else {
            res += 3;
        }
        cout << res << "\n";
    }
    return 0;
}