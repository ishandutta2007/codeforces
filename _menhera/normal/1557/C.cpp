#include <iostream>
using namespace std;


const int MOD = 1e9+7;
int ipow(int a, long long b)
{
    if(b == 0) return 1;
    int ans = ipow(a, b/2);
    ans = 1LL*ans*ans%MOD;
    if(b&1) ans = 1LL*ans*a%MOD;
    return ans;
}

int solve(int N, int K) {
    if(N%2 == 1) return ipow(ipow(2, N-1)+1, K);

    int ans = ipow(ipow(2, N-1)-1, K);
    for(int i=1; i<=K; ++i)
        ans = (ans+1LL*ipow(ipow(2, N-1)-1, i-1)*ipow(ipow(2, N), K-i))%MOD;
    return ans;
}
int main() {
    int T; cin >> T;
    while(T--) {
        int N, K; cin >> N >> K;
        cout << solve(N, K) << endl;
    }
}