#include <cstdio>
#include <string>
using namespace std;

const string name[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int N;
char s[10];

void load() {
    scanf("%d%s", &N, s);
}

bool cmp(int x) {
    if (name[x].size() != N) return 0; 
    for (int i = 0; i < N; i++) 
        if (s[i] != '.' && s[i] != name[x][i]) 
            return 0;
    return 1;
}

void solve() {
    for (int i = 0; i < 8; i++) 
        if (cmp(i)) {
            puts(name[i].c_str());
            break;
        }
}

int main() {
    load();
    solve();
    return 0;
}