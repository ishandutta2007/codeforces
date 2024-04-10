#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const string key[] = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};

char dir, s[105];

void load() {
    scanf(" %c%s", &dir, s);
}

int x[1000], y[1000];

void solve() {
    int N = strlen(s);
    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 10; j++) {
            x[key[i][j]] = i;
            y[key[i][j]] = j;
        }
    for (int i = 0; i < N; i++) 
        printf("%c", dir == 'L' ? key[x[s[i]]][y[s[i]] + 1] : key[x[s[i]]][y[s[i]] - 1]);
    printf("\n"); 
}

int main() {
    load();
    solve();
    return 0;
}