#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair <ll, int> pii;
typedef vector <pii> vpii;

const ll BASE1 = 10007;
const int BASE2 = 3137;
const int MOD = 1000000007;
 
int N, M;
vpii S, T;
vpii hash;
ll pot1;
int pot2;

vpii get(int len) {
    char prev;
    ll cnt = 0;
    vpii res;
    for (int i = 0; i < len; i++) {
        int l;
        char c;
        scanf("%d-%c", &l, &c);
        if (i && c != prev) {
            res.push_back(pii(cnt, prev));
            cnt = 0;
        }
        cnt += l;
        prev = c;
    }
    res.push_back(pii(cnt, prev));
    return res;
}

void load() {
    scanf("%d%d", &N, &M);
    T = get(N);
    S = get(M); 
}

inline int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    else if (x < 0) x += MOD;
    return x;
}

inline int mul(int x, int y) {
    return (ll)x * y % MOD;
}

inline ll con(pii p) {
    return 1000 * p.first + p.second;
}

pii get(int lo, int hi) {
    pii res;
    res.first = hash[hi].first - hash[lo - 1].first * pot1;
    res.second = add(hash[hi].second, -mul(hash[lo - 1].second, pot2));
    return res;
}

ll solve() {
    if (S.size() > T.size()) return 0;
    
    ll sol = 0;
    if (S.size() == 1) {
        for (int i = 0; i < T.size(); i++)
            if (T[i].second == S[0].second)
                sol += max(T[i].first - S[0].first + 1, 0ll);
        return sol;
    }
    
    hash.push_back(pii(0, 0));
    for (int i = 0; i < T.size(); i++)
        hash.push_back(pii(hash.back().first * BASE1 + con(T[i]), add(mul(hash.back().second, BASE2), (int)(con(T[i]) % (ll)MOD))));
    
    int sz = S.size();
    pot1 = 1;
    pot2 = 1;
    pii val(0, 0);
    for (int i = sz - 2; i > 0; i--) {
        val.first += pot1 * con(S[i]);
        val.second = add(val.second, mul(pot2, (int)(con(S[i]) % (ll)MOD)));
        pot1 *= BASE1;
        pot2 = mul(pot2, BASE2);
    }
    
    for (int i = 0; i + sz <= T.size(); i++) {
        if (T[i].first < S[0].first || T[i].second != S[0].second) continue;
        if (T[i + sz - 1].first < S[sz - 1].first || T[i + sz - 1].second != S[sz - 1].second) continue;
        sol += sz == 2 || get(i + 2, i + sz - 1).second == val.second;
    }
    
    return sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}