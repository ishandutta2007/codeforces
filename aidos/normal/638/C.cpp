#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long int
#define ull unsigned long long
#define pii pair < int, int > 
#define pll pair < ll, ll > 
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define file "a"

const int inf = (int)1e9;

using namespace std;

int n;
vector < pii > g[200200];
vector < int > ans[200200];

void dfs(int v, int p, int which){
    int cur = 0;
    forit(it, g[v]){
        int to = (*it).f;
        int id = (*it).s;
        if (to == p) continue;
        if (cur == which) cur++;
        ans[cur].pb(id);
        dfs(to, v, cur);
        cur++;
    }
}

int main(){
    #ifdef LOCAL
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);
    #endif

    scanf("%d", &n);
    for (int i=1;i<n;i++){
        int a, b; scanf("%d%d", &a, &b);
        g[a].pb(mp(b, i));
        g[b].pb(mp(a, i));
    }

    dfs(1,-1,-1);

    int N = 0;
    for (int i=0;i<200200;i++){
        if (ans[i].empty()){
            N = i;
            break;
        }
    }

    printf ("%d\n", N);
    for (int i=0;i<N;i++){
        printf("%d", sz(ans[i]));
        forit(it, ans[i]){
            printf(" %d", *it);
        }
        printf("\n");
    }


    #ifdef LOCAL
        cerr <<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
    #endif

    return 0;
}