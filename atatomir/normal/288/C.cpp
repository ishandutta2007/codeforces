#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>


using namespace std;


#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 1000011

int n, i;
bool us[maxN];
int p[maxN];
vector<int> who[2];
ll ans;

void solve(int bit) {
    int i;
    int mask = (1 << (bit + 1)) - 1;
    
    who[0].clear();
    who[1].clear();
    
    for (i = 0; i <= n; i++)
        if (!us[i])
            who[(i >> bit) & 1].pb(i);
            
    if (who[0].size() < who[1].size()) {
        for (auto e : who[0]) {
            p[e] = e ^ mask;
            p[e ^ mask] = e;
            us[e] = us[e ^ mask] = true;
        }
    } else {
        for (auto e : who[1]) {
            p[e] = e ^ mask;
            p[e ^ mask] = e;
            us[e] = us[e ^ mask] = true;
        }
    }
}

int main() {
    
    
    scanf("%d", &n);
    who[0].reserve(n + 13);
    who[1].reserve(n + 13);
    
    for (int bit = 30; bit >= 0; bit--)
        solve(bit);
        
    for (i = 0; i <= n; i++) ans += 1LL * (i ^ p[i]);
    
    printf("%lld\n", ans);
    for (i = 0; i <= n; i++) printf("%d ", p[i]);
    
    
    return 0;
}