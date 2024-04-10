#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

const int MAXN = 100005;
const int INF = 0x3f3f3f3f;

int N, K;
int a[MAXN];
vector <int> V[MAXN];

int input() {
    char buff[15];
    scanf("%s", buff);
    if (buff[0] == '?') return INF;
    int sign = buff[0] == '-', num = 0;
    for (int i = sign; buff[i]; i++)
        num = 10 * num + buff[i] - '0';
    return sign ? -num : num;
}

void load() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++)
        a[i] = input();
}

void set(int mod, int lo, int hi) {
    if (V[mod][hi] - V[mod][lo] < hi - lo) {
        puts("Incorrect sequence");
        exit(0);
    }
    
    int l = V[mod][lo] + 1;
    int r = V[mod][hi] - 1;
    if (l >= 0) {
        for (int i = lo; i < hi - 1; i++)
            a[mod + i * K] = l + i - lo;
        return;
    }
    if (r <= 0) {
        for (int i = hi - 2; i >= lo; i--)
            a[mod + i * K] = r - hi + i + 2;
        return; 
    }   
    if (l + r > 0) {
        if (l + (hi - lo) / 2 < 0) {
            for (int i = lo; i < hi - 1; i++)
                a[mod + i * K] = -((hi - lo) / 2 - 1) + i - lo;
            return;
        }
        for (int i = lo; i < hi - 1; i++)
            a[mod + i * K] = l + i - lo;
        return;
    }
    if (r >= (hi - lo) / 2 - 1 && l + (hi - lo - 1) / 2 <= 0) {
        for (int i = lo; i < hi - 1; i++)
            a[mod + i * K] = -(hi - lo - 1) / 2 + i - lo;
        return;
    }
    for (int i = hi - 2; i >= lo; i--)
        a[mod + i * K] = r - hi + i + 2;
}

void solve() {
    for (int i = 0; i < K; i++) 
        V[i].push_back(-INF);
    for (int i = 0; i < N; i++)
        V[i % K].push_back(a[i]);
    for (int i = 0; i < K; i++)
        V[i].push_back(INF + 5);
        
    for (int i = 0; i < K; i++) {   
        int last = 0;
        for (int j = 1; j < V[i].size(); j++)
            if (V[i][j] != INF) {
                set(i, last, j);  
                last = j;
            }
    }
    
    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}