#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

int n, m, col[777], Head[777], Next[5555555], Go[5555555], Cnt = 0, tim = 0;

void addedge(int x, int y) {
    Go[++Cnt] = y;
    Next[Cnt] = Head[x];
    Head[x] = Cnt;
    Go[++Cnt] = x;
    Next[Cnt] = Head[y];
    Head[y] = Cnt;
}

int ask(vector <int> V) {
    if(V.size() <= 1) return 0;
    printf("? %d\n", V.size());
    for(int i = 0; i < V.size(); i++) printf("%d ", V[i]);
    putchar('\n');
    fflush(stdout);
    int x;
    scanf("%d", &x);
    return x;
}

int cedge(int x, vector <int> V) {
    int b = ask(V);
    V.push_back(x);
    int a = ask(V);
    return a - b;
}

void GG(vector <int> V) {
    printf("N %d\n", V.size());
    for(int i = 0; i < V.size(); i++) printf("%d ", V[i]);
    putchar('\n');
    fflush(stdout);
    exit(0);
}

void OK(vector <int> V) {
    printf("Y %d\n", V.size());
    for(int i = 0; i < V.size(); i++) printf("%d ", V[i]);
    putchar('\n');
    fflush(stdout);
    exit(0);
}

vector <int> get1() {
    vector <int> V;
    V.clear();
    for(int i = 1; i <= n; i++) if(col[i] == 1) V.push_back(i);
    return V;
}

vector <int> get0() {
    vector <int> V;
    V.clear();
    for(int i = 1; i <= n; i++) if(col[i] == 0) V.push_back(i);
    return V;
}

vector <int> get_f1() {
    vector <int> V;
    V.clear();
    for(int i = 1; i <= n; i++) if(col[i] == -1) V.push_back(i);
    return V;
}

int Solve(int x, vector <int> V, int ans = -1) {
    vector <int> V1, V2;
    V1.clear();
    V2.clear();
    int s = V.size(), md = s / 2, t;
    if(ans == -1) t = cedge(x, V); else t = ans;
    if(!t) return 0;
    if(s == 1) {
        addedge(x, V[0]);
        return 1;
    }
    for(int i = 0; i < md; i++) V1.push_back(V[i]);
    for(int i = md; i < s; i++) V2.push_back(V[i]);
    int tmp = Solve(x, V1);
    Solve(x, V2, t - tmp);
    return t;
}

vector <int> VGG;

void getGG(int x, int c = 0) {
    col[x] = c;
    VGG.push_back(x);
    for(int T = Head[x]; T; T = Next[T])
        if(col[Go[T]] == -1) getGG(Go[T], !c);
        else if(col[Go[T]] == col[x]) GG(VGG);
    VGG.pop_back();
}

void Search(int x, int c = 0) {
    // now col[x] == -1, so get0 and get1 are both not contain x.
    col[x] = -1;
    if(c == 0 && cedge(x, get0())) {
        Solve(x, get0());
        memset(col, -1, sizeof col);
        getGG(x);
    } else if(c == 1 && cedge(x, get1())) {
        Solve(x, get1());
        memset(col, -1, sizeof col);
        getGG(x);
    }
    col[x] = c;
    Solve(x, get_f1());
    vector <int> V;
    V.clear();
    for(int T = Head[x]; T; T = Next[T]) if(col[Go[T]] == -1) col[Go[T]] = !c, V.push_back(Go[T]);
    for(int i = 0; i < V.size(); i++) Search(V[i], !c);
}

int main() {
    scanf("%d", &n);
    memset(col, -1, sizeof col);
    Search(1);
    //no need to search the other edges.
    vector <int> V;
    V.clear();
    for(int i = 1; i <= n; i++) if(col[i] == 0) V.push_back(i);
    OK(V);
    return 0;
}