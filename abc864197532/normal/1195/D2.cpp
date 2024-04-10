#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair <int,int>
int MOD = 998244353;
 
lli myPow(int a, int b) {
    lli sum = 1;
    fop (i,0,b) sum = sum * a % MOD;
    return sum;
}
 
 
int main () {
	int n;
	cin >> n;
	string s[n];
	int nums[10];
	fop (i,0,10) nums[i] = 0;
	fop (i,0,n) {
	    cin >> s[i];
	    nums[s[i].length()-1]++;
	    reverse(s[i].begin(), s[i].end());
	}
	lli ans = 0, now = 0;
	fop (i,0,n) {
	    fop (j,0,10) {
            if (s[i].length() < j + 1) {
                ans += (1ll * nums[j] * now % MOD);
            } else {
                now = 0;
                fop (k,0,j+1) now = (now + (s[i][k] - '0') * myPow(10,2*k+1)) % MOD;
                fop (k,0,s[i].length()-j-1) now = (now + (s[i][j+k+1] - '0') * myPow(10,2*j+2+k)) % MOD;
                ans += (1ll * nums[j] * now % MOD);
            }
            ans %= MOD;
	    }
	    fop (j,0,10) {
            if (s[i].length() < j + 1) {
                ans += (1ll * nums[j] * now % MOD);
            } else {
                now = 0;
                fop (k,0,j+1) now = (now + (s[i][k] - '0') * myPow(10,2*k)) % MOD;
                fop (k,0,s[i].length()-j-1) now = (now + (s[i][j+k+1] - '0') * myPow(10,2*j+2+k)) % MOD;
                ans += (1ll * nums[j] * now % MOD);
            }
            ans %= MOD;
	    }
    }
    if (ans < 0) ans += MOD;
    cout << ans << endl;
}