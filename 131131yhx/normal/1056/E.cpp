#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#define M 1000010

using namespace std;

typedef long long ll;

const int Pmx = 3;

const ll P[Pmx] = {1000000007ll, 1000000009ll, 998244353ll};

ll B[Pmx], S[M][Pmx], _0[Pmx], _1[Pmx], _S[M][Pmx], n, m;

char ch1[M], ch2[M];

bool check(int x, int y) {
    int pt = 0;
    _0[0] = (_1[0] = -1);
    for(int i = 1; i <= n; i++) {
        ll tmp[Pmx];
        memset(tmp, 0, sizeof tmp);
        if(ch1[i] == '0') {
            for(int j = 0; j < Pmx; j++) {
                tmp[j] = ((S[pt + x][j] - S[pt][j]) % P[j] + P[j]) % P[j];
                tmp[j] = (tmp[j] * _S[m - pt][j]) % P[j];
            }
            if(_0[0] == -1) memcpy(_0, tmp, sizeof tmp);
            else {
                for(int j = 0; j < Pmx; j++)
                    if(_0[j] != tmp[j]) return 0;
            }
            pt += x;
        } else {
            for(int j = 0; j < Pmx; j++) {
                tmp[j] = ((S[pt + y][j] - S[pt][j]) % P[j] + P[j]) % P[j];
                tmp[j] = (tmp[j] * _S[m - pt][j]) % P[j];
            }
            if(_1[0] == -1) memcpy(_1, tmp, sizeof tmp);
            else {
                for(int j = 0; j < Pmx; j++)
                    if(_1[j] != tmp[j]) return 0;
            }
            pt += y;
        }
    }
    for(int j = 0; j < Pmx; j++) if(_0[j] != _1[j]) return 1;
    return 0;
}

int main() {
    srand((unsigned) time (NULL));
    for(int i = 0; i < Pmx; i++) B[i] = rand() % 3333 + 233;
    scanf("%s%s", ch1 + 1, ch2 + 1);
    n = strlen(ch1 + 1), m = strlen(ch2 + 1);
    for(int i = 0; i < Pmx; i++) {
        _S[0][i] = 1;
        for(int j = 1; j <= m + 1; j++)
            _S[j][i] = _S[j - 1][i] * B[i] % P[i];
    }
    for(int i = 1; i <= m; i++)
        for(int j = 0; j < Pmx; j++)
            S[i][j] = (S[i - 1][j] + ch2[i] * _S[i][j]) % P[j];
    ll _0 = 0, _1 = 0, ans = 0;
    for(int i = 1; i <= n; i++) if(ch1[i] == '0') _0++; else _1++;
    for(int i = 1; i * _0 < m; i++)
        if((m - i * _0) % _1 == 0) {
            ans += check(i, (m - i * _0) / _1);
        }
    printf("%lld\n", ans);
    return 0;
}