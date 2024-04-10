#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 200005;

int N;
int a[MAXN], old[MAXN];
int bio[MAXN];
vector < vector <int> > cyc;
int root;

void load() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", a + i);    
}

void go(int x) {
    if (bio[x]) return;
    
    vector <int> curr;
    for (; !bio[x]; x = a[x]) {
        curr.push_back(x);
        bio[x] = 1;
    }
    
    if (bio[x] == 1) {
        vector <int> C;   
        C.push_back(x);
        for (int c = a[x]; c != x; c = a[c])
            C.push_back(c);
        cyc.push_back(C);
        if (C.size() == 1) root = C[0];
    }
    
    for (int i = 0; i < curr.size(); i++)
        bio[curr[i]] = 2;
}

void solve() {
    memcpy(old, a, sizeof old);
    for (int i = 1; i <= N; i++) 
        go(i);
    
    if (!root) root = cyc[0][0];
    for (int i = 0; i < cyc.size(); i++)
        a[cyc[i][0]] = root;
    
    int sol = 0;
    for (int i = 1; i <= N; i++)
        sol += a[i] != old[i];
    
    printf("%d\n", sol);
    for (int i = 1; i <= N; i++)
        printf("%d ", a[i]);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}