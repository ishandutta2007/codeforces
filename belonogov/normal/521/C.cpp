#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define getTime() cerr << (clock() * 1.0 / CLOCKS_PER_SEC) << endl
#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const int INF = 1e9;
const long long MOD = 1e9 + 7;

int n, k;
char s[N];
int d[N];
int pd[N];
long long ck[N];
long long p10[N];

long long getSum(int l, int r) {
    return pd[r] - pd[l];
}

void read() {
    scanf("%d%d", &n, &k);
    scanf("%s", s);
    for (int i = 0; i < n; i++)
        d[i] = s[i] - '0';
    for (int i = 0; i < n; i++)
        pd[i + 1] = pd[i] + d[i];
}

long long binPow(long long a, long long b) {
    long long r = 1;
    for (; b > 0; b /= 2) {
        if (b % 2 == 1)
            r = (r * a) % MOD;
        a = (a * a) % MOD;
    }
    return r;
}

void solve() {
    long long ans = 0; 
    long long c = 1; 
    for (int i = k - 1; i <= n; i++) {
        ck[i] = c;
        c = (c * (i + 1)) % MOD;
        c = (c * binPow((i + 1) - (k - 1), MOD - 2)) % MOD;
    } 
    //for (int i = 0; i <= n; i++)
        //cerr << ck[i] << " ";
    //cerr << endl;

    p10[0] = 1;
    for (int i = 0; i <= n; i++) 
        p10[i + 1] = (p10[i] * 10) % MOD;
    
    long long sum = 0; 
    int t = n - 2 - (k - 1);
    for (int i = k - 1; i <= n - 2; i++, t--)
        sum = (sum + p10[t] * ck[i]) % MOD;

    //cerr << "sum : " << sum << endl;

    for (int i = 0; i <= k - 1; i++)
        ans = (ans + d[i] * sum) % MOD;

    //cerr << "ans: " <<  ans << endl;
   
    long long tmp = 0;
    for (int i = n - 2; i >= k; i--) {
        int t = n - 2 - i;
        tmp = (tmp + p10[t] * ck[n - 2 - t]) % MOD;
        ans = (ans + tmp * d[i]) % MOD;
    }

    //cerr << "ans: " <<  ans << endl;

    
    long long C = 1;
    for (int i = k; i < n; i++) {
        int t = n - 1 - i;
        ans = (ans + ((d[i] * p10[t]) % MOD) * C) % MOD;
        C = (C * (i + 1)) % MOD;
        C = (C * binPow((i + 1 - k), MOD - 2)) % MOD;
    }
    cout << ans << endl;
}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        while (true) {
            read();
            solve();
            printAns();
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}