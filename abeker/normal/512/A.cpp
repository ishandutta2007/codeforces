#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

const int MAXN = 105;

int N;
char word[MAXN][MAXN];
vector <int> E[30], order;
int bio[30];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) 
        scanf("%s", word[i]);
}

void bye() {
    puts("Impossible");
    exit(0);
}

void cmp(int x) {
    int k = strlen(word[x - 1]), l = strlen(word[x]);
    for (int i = 0; i < k && i < l; i++) 
        if (word[x - 1][i] != word[x][i]) {
            E[word[x][i] - 'a'].push_back(word[x - 1][i] - 'a');
            return;
        }
    if (k > l) bye();
}

void dfs(int x) {
    if (bio[x] == 1) bye();
    if (bio[x] == 2) return;
    bio[x] = 1;
    for (int i = 0; i < E[x].size(); i++) 
        dfs(E[x][i]);
    order.push_back(x);
    bio[x] = 2;
}

void solve() {
    for (int i = 1; i < N; i++)
        cmp(i);
    for (int i = 0; i < 26; i++) 
        dfs(i);
    for (int i = 0; i < order.size(); i++) 
        printf("%c", order[i] + 'a');
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}