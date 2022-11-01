#include <bits/stdc++.h> 

using namespace std;

const int N = 1e5 + 10;

char s[N];
int f0[30], f1[30];
string w = "Bulbasaur";

int main (int argc, char const *argv[]) {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; ++i) {
        if (s[i] >= 'A' and s[i] <= 'Z') {
            ++f0[s[i] - 'A'];
        }
        if (s[i] >= 'a' and s[i] <= 'z') {
            ++f1[s[i] - 'a'];
        }
    }
    int tot = f0[w[0] - 'A'];
    for (int i = 1; i < (int) w.size(); ++i) {
        if (w[i] == 'u' or w[i] == 'a') tot = min(tot, f1[w[i] - 'a']/2);
        else tot = min(tot, f1[w[i] - 'a']);
    }
    printf("%d\n", tot);
    return 0;
}