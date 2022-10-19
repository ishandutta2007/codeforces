#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector <ll> :: iterator vllit;

const int MAXN = 30;

int N, K;
int a[MAXN];
vector <ll> sums[2][MAXN / 2];
ll fact[MAXN];
ll S;

void load() {
    scanf("%d%d%I64d", &N, &K, &S);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

void go(int lo, int hi, int w) {
    int pot = 1;
    for (int i = 0; i < hi - lo; i++)
        pot *= 3;
        
    for (int i = 0; i < pot; i++) {
        int mask = i;
        ll sum = 0;
        bool ok = true;
        int cnt = 0;
        
        for (int j = lo; j < hi; j++) {
            if (mask % 3 == 2) {
                if (a[j] > 18) { 
                    ok = false;  
                    break;
                }
                sum += fact[a[j]];
                cnt++;
            }
            else if (mask % 3 == 1)
                sum += (ll)a[j];
            mask /= 3;
        }
        
        if (ok) sums[w][cnt].push_back(sum);
    }
}

inline int occ(vector <ll> &V, ll val) {
    pair <vllit, vllit> p = equal_range(V.begin(), V.end(), val);
    return p.second - p.first;
}

ll solve() {
    fact[0] = 1ll;
    for (int i = 1; i < 19; i++)
        fact[i] = fact[i - 1] * (ll)i;
         
    go(0, N / 2, 0);
    go(N / 2, N, 1);    
    
    for (int i = 0; i <= N / 2 + 1; i++)
        sort(sums[1][i].begin(), sums[1][i].end());
        
    ll sol = 0;
    for (int i = 0; i <= N / 2; i++)
        for (int j = 0; j < sums[0][i].size(); j++)
            for (int k = 0; k + i <= K && k <= N / 2 + 1; k++)
                sol += (ll)occ(sums[1][k], S - sums[0][i][j]);
    
    return sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}