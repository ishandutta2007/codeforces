#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#define int long long
#define P 1000000000
#define M 200010

using namespace std;

typedef long long ll;

char A[1000010], B[1000010], S[1000010];

int k, n, mp[55], used[55];

vector <int> V;

int Boom() {
    for(int i = (int) V.size() - 1; i >= 0; i--) {
        int s = S[V[i]];
        used[mp[s]]--;
        mp[s]--;
        while(mp[s] != -1 && used[mp[s]]) mp[s]--;
        if(mp[s] != -1) {used[mp[s]] = 1; return V[i] + 1;}
    }
    return -1;
}

void Solve() {
    scanf("%lld", &k);
    scanf("%s%s%s", S + 1, A + 1, B + 1);
    n = strlen(S + 1);
    for(int i = 1; i <= n; i++) S[i] -= 'a', A[i] -= 'a', B[i] -= 'a';
    memset(mp, -1, sizeof mp);
    memset(used, 0, sizeof used);
    int gg = n + 1;
    V.clear(); // notice empty
    for(int i = 1; i <= n; i++) {
        if(mp[S[i]] == -1) { //!!!
            if(used[B[i]]) {
                mp[S[i]] = B[i];
                used[B[i]]++;
                V.push_back(i);
                gg = Boom();
                if(gg == -1) {
                    puts("NO");
                    return;
                }
                break;
            } else {
                mp[S[i]] = B[i], used[B[i]] = 1;
                V.push_back(i);
            }
        } else {
            if(mp[S[i]] > B[i]) {
                gg = Boom();
                if(gg == -1) {
                    puts("NO");
                    return;
                }
                break;
            } else if(mp[S[i]] < B[i]) {
                gg = i;
                break;
            }
        }
    }
    for(int i = gg; i <= n; i++) if(mp[S[i]] == -1) {
        for(int j = k - 1; j >= 0; j--) if(!used[j]) {
            mp[S[i]] = j;
            used[j] = 1;
            break;
        }
    }
    for(int i = 0; i < k; i++) if(mp[i] == -1) {
        for(int j = k - 1; j >= 0; j--) if(!used[j]) {
            mp[i] = j;
            used[j] = 1;
            break;
        }
    } //!!!
    for(int i = 1; i <= n; i++) S[i] = mp[S[i]];
    for(int i = 1; i <= n; i++) if(S[i] != A[i]) {
        if(S[i] > A[i]) {
            puts("YES");
            for(int j = 0; j < k; j++) putchar('a' + mp[j]);
            putchar('\n');
            return;
        } else if(S[i] < A[i]) {
            puts("NO");
            return;
        }
    }
    puts("YES");
    for(int j = 0; j < k; j++) putchar('a' + mp[j]);
    putchar('\n');
    return;
}

signed main() {
    int Cas;
    scanf("%lld", &Cas);
    while(Cas--) {
        Solve();
    }
    return 0;
}