#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define pr(x) { cerr << #x << " = " << x << endl; }
#define stack sdfsdfds
const int N = 111; 
const int INF = 1e9;

int n;
char s[N][N]; 
vector < int > e[N];
bool use[N];
int p[N];
vector < int > stack;

void ret() {
    printf("Impossible\n");
    exit(0);
}

void dfs(int v) {
    use[v] = 1;
    for (auto u: e[v])
        if (!use[u])
            dfs(u);
    stack.pb(v);
}

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        int j = 0;
        int n1 = strlen(s[i]);
        int n2 = strlen(s[i + 1]);
        for (; j < n1 && j < n2 && s[i][j] == s[i + 1][j]; j++);
        if ((j == n1 || j == n2) && n1 > n2) {
            ret();
        }
        if (j != n1 && j != n2) {
            e[s[i][j] - 'a'].pb(s[i + 1][j] - 'a');
        }
    }
    for (int i = 0; i < 26; i++)
        if (!use[i])
            dfs(i);
    reverse(stack.begin(), stack.end());
    //for (int i = 0; i < 26; i++)
        //for (auto u: e[i])
            //cerr << i << " " << u <<  endl;
    for (int i = 0; i < 26; i++)
        p[stack[i]] = i;
    for (int v = 0; v < 26; v++)
        for (auto u: e[v]) {
            //cerr << p[v] << " " << p[u] << endl;
            if (p[v] > p[u]) {
                ret();
            }
        }
    for (int i = 0; i < 26; i++)
        printf("%c", (char)(stack[i] + 'a'));

}

void solve() {

}


void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        while (true) {
            read();
            solve();
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}