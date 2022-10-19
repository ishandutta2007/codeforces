#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 100005;

int N, T;
char a[MAXN], b[MAXN];
char sol[MAXN];
vector <int> V;

void load() {
    scanf("%d%d%s%s", &N, &T, a, b);
}

char get(char x, char y) {
    for (int i = 0; i < 26; i++)
        if ('a' + i != x && 'a' + i != y) return 'a' + i;
    return -1;
}

void solve() {
    T = N - T;
    int p = 0;
    for (int i = 0; i < N; i++) 
        p += a[i] == b[i];
    if (T > (p + N) / 2) {
        puts("-1");
        return;
    }
    
    for (int i = 0; i < N; i++) 
        if (a[i] == b[i]) {
            if (T) {
                sol[i] = a[i];
                T--;
            }
            else sol[i] = get(a[i], b[i]);
        }
        else V.push_back(i);
    
    for (int i = 0; i < T; i++) 
        sol[V[i]] = a[V[i]];
        
    for (int i = 0; i < T; i++)
        sol[V[T + i]] = b[V[T + i]];
    
    for (int i = 2 * T; i < V.size(); i++)
        sol[V[i]] = get(a[V[i]], b[V[i]]);
    
    for (int i = 0; i < N; i++)
        printf("%c", sol[i]);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}