#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define getTime() cerr << (clock() * 1.0 / CLOCKS_PER_SEC) << endl
#define equal equalll
#define less lesss
const int N = 1e5 + 100;
const int INF = 1e9;
const long long MOD = 1e9 + 7;

int n;
char s[N];

void read() {
    scanf("%d", &n);
    scanf("%s", s);
}

void solve() {
    map < char, int > q;
    for (int i = 0; i < n; i++)
        q[s[i]]++;
    vector < int > b;
    for (auto x: q)
        b.pb(x.sc);
    sort(b.begin(), b.end());
    int cnt = 0;
    for (auto x: b)
        cnt += x == b.back();
    long long ans = 1;
    for (int i = 0; i < n; i++)
        ans = (ans * cnt) % MOD;
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