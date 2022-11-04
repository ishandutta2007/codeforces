#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#define mo 1000000007
#define M 1500010

using namespace std;

typedef long long ll;

const int C = 30;

bool X[33][M];

int P[M];

ll k, m, F[33], G[11111];

string S;

int match(bool *X, int l, int r) {
    int t = -1, ans = 0;
    for(int i = l; i <= r; i++) {
        while(t != -1 && S[t + 1] != X[i]) t = P[t];
        if(S[t + 1] == X[i]) t++;
        if(t == S.size() - 1) {
            ans++;
            t = P[t];
        }
    }
    return ans;
}

int main() {
    scanf("%lld%lld", &k, &m);
    X[1][1] = 0;
    X[2][1] = 1;
    F[1] = (F[2] = 1);
    for(int i = 3; i <= C; i++) {
        F[i] = F[i - 1] + F[i - 2];
        for(int j = 1; j <= F[i - 1]; j++) X[i][j] = X[i - 1][j];
        for(int j = 1; j <= F[i - 2]; j++) X[i][j + F[i - 1]] = X[i - 2][j];
    }
    for(int i = 1; i <= C; i++)
        for(int j = 1; j <= F[i]; j++)
            X[i][j + F[i]] = X[i][j];
    while(m--) {
        cin >> S;
        int K = 0;
        while(F[K] < 3 * S.size()) K++;
        P[0] = -1;
        int t = -1;
        for(int i = 0; i < S.size(); i++) S[i] -= 'a';
        for(int i = 1; i < S.size(); i++) {
            while(t != -1 && S[t + 1] != S[i]) t = P[t];
            if(S[t + 1] == S[i]) t++;
            P[i] = t;
        }
        for(int i = 1; i <= K; i++) G[i] = match(X[i], 1, F[i]);
        ll A = match(X[K - 1], F[K - 1] - S.size() + 2, F[K - 1] + S.size() - 1);
        ll B = match(X[K], F[K] - S.size() + 2, F[K] + S.size() - 1);
        if(k <= 10000) {
            for(int i = K + 1; i <= k; i += 2) {
                G[i] = (G[i - 1] + G[i - 2] + B) % mo;
                G[i + 1] = (G[i] + G[i - 1] + A) % mo;
            }
            printf("%lld\n", (G[k] % mo + mo) % mo);
        }
    }
    return 0;
}