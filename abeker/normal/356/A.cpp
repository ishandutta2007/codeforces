#include <cstdio>
#include <vector>
#include <set>
using namespace std;

const int MAXN = 300005;

int N, M;
int who[MAXN];
set <int> S;

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        S.insert(i);
    
    while (M--) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        vector <int> todo;
        for (set <int> :: iterator it = S.lower_bound(l); it != S.end() && *it <= r; it++)
            if (*it != x) todo.push_back(*it);
        for (int i = 0; i < todo.size(); i++) {
            who[todo[i]] = x;
            S.erase(todo[i]);
        }
    }
    
    for (int i = 1; i <= N; i++)
        printf("%d ", who[i]);
    puts("");
    
    return 0;
}