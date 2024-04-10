#include <cstdio>
using namespace std;

const int MAXN = 100005;

char s[MAXN];

int main() {
    scanf("%s", s);
    int pos = 0;
    for (; s[pos] == 'a'; pos++);
    if (!s[pos]) s[pos - 1] = 'z';
    for (; s[pos] && s[pos] != 'a'; pos++)
        s[pos]--;
    puts(s);
    return 0;
}