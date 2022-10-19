#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXL = 1000005;

int N;
int cnt[MAXL];
vector <int> V;

void load() {
    scanf("%d", &N);
    while (N--) {
        int x; 
        scanf("%d", &x);
        cnt[x]++;
    }
}

ll solve() {
    int last = MAXL + 1;
    for (int i = MAXL - 1; i >= 0; i--) {
        if (!cnt[i]) continue;
        if (last == i + 1 && cnt[last] % 2) {
            cnt[last]--;
            cnt[i]++;
        }
        last = i;
    }
    
    for (int i = 0; i < MAXL; i++) 
        for (cnt[i] /= 2; cnt[i]; cnt[i]--) 
            V.push_back(i);
    
    ll sol = 0;
    for (int i = (int)V.size() - 2; i >= 0; i -= 2)
        sol += (ll)V[i] * V[i + 1];
    return sol;
}

int main() {
    load();
    //N = 100000;
    //while (N--) cnt[1000000]++;
    printf("%I64d\n", solve());
    return 0;
}