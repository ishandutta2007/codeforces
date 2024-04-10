#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int n, Mn[100010], Pr[100010], Ans[100010];

bool vis[100010];

vector <int> V;

int main() {
    scanf("%d", &n);
    V.clear();
    for(int i = 2; i < n && i * i <= n; i++)
        if(n % i == 0) V.push_back(i), V.push_back(n / i);
    if(!V.size()) {
        puts("NO");
        return 0;
    }
    sort(V.begin(), V.end());
    memset(Mn, 63, sizeof Mn);
    Mn[0] = 0;
    vector <int> D(0);
    D.push_back(0);
    int p = V[0];
    for(int i = 0; i < D.size(); i++) {
        int s = D[i];
        vis[s] = 0;
        for(int j = 0; j < V.size(); j++) {
            int g = (s + V[j]) % p, ds = Mn[s] + (s + V[j]) / p;
            if(Mn[g] > ds) {
                Mn[g] = ds;
                Pr[g] = j;
                if(!vis[g]) D.push_back(g);
            }
        }
    }
    if(Mn[p - 1] > (n - 1) / p) {
        puts("NO");
        return 0;
    }
    Ans[0] = (n - 1) / p - Mn[p - 1];
    for(int i = p - 1; i != 0; i = ((i - V[Pr[i]]) % p + p) % p)
        Ans[Pr[i]]++;
    puts("YES");
    int tot = 0;
    for(int i = 0; i < V.size(); i++) if(Ans[i]) tot++;
    printf("%d\n", tot);
    for(int i = 0; i < V.size(); i++) if(Ans[i]) printf("%d %d\n", Ans[i], n / V[i]);
    return 0;
}