#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int nums[9] = {1,11,111,1111,11111,111111,1111111,11111111,111111111};
        int ans = 0;
        fop (i,0,9) {
            fop (j,1,10) {
                if (nums[i] * j <= n) ans++;
            }
        }
        cout << ans << endl;
    }
}