#include <cstdio>
#include <stack>
using namespace std;

const int MAXN = 100005;

char s[MAXN];
stack <char> S;

void load() {
    scanf("%s", s);
}

bool solve() {
    for (int i = 0; s[i]; i++)
        if (!S.empty() && s[i] == S.top()) S.pop();
        else S.push(s[i]);
    return S.empty();
}

int main() {
    load();
    puts(solve() ? "Yes" : "No");
    return 0;
}