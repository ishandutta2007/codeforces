#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

typedef long long ll;

const int MAXN = 100005;

const int MOD = 1000000007;
const int PHI = 1000000006;

int N;
string s[MAXN];
int digit[MAXN];

void parse(int x) {
    string buff;
    cin >> buff;
    digit[x] = buff[0] - '0';
    s[x] = buff.substr(3, buff.size() - 3);
}

void load() {
    digit[0] = 10;
    cin >> s[0] >> N;
    for (int i = 1; i <= N; i++) 
        parse(i);
}

int val[15], len[15];
int _val[15], _len[15];

int mul(int x, int y) { return (int)((ll)x * (ll)y % (ll)MOD); }

int pow(int x, int y) {
    if (!y) return 1;
    if (y & 1) return mul(x, pow(x, y - 1)); 
    int res = pow(x, y >> 1);
    return mul(res, res);
}

int solve() {
    for (int i = 0; i < 15; i++) {
        val[i] = i;
        len[i] = 1;
    }   
    for (int i = N; i >= 0; i--) {
        for (int j = 0; j < 15; j++) { 
            _val[j] = val[j];
            _len[j] = len[j];
        }
        int x = digit[i];
        string t = s[i];
        val[x] = len[x] = 0; 
        if (t.empty()) continue;
        for (int j = (int)t.size() - 1; j >= 0; j--) {
            val[x] = (val[x] + mul(_val[t[j] - '0'], pow(10, len[x]))) % MOD;
            len[x] = (len[x] + _len[t[j] - '0']) % PHI;
        }
    }
    return val[10];
}

int main() {
    ios::sync_with_stdio(0);
    load();
    printf("%d\n", solve());
    return 0;
}