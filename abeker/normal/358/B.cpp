#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int MAXN = 100005;

int N;
char buff[MAXN], text[MAXN];
string s;

void load() {
    scanf("%d", &N);    
    while (N--) {
        scanf("%s", buff);
        s += "<3";
        s += buff;
    }
    s += "<3";
    scanf("%s", text);
}

bool solve() {
    int j = -1;
    int len = strlen(text);
    for (int i = 0; i < s.size(); i++)
        for (++j; j < len && text[j] != s[i]; j++);
    return j < len;
}

int main() {
    load();
    puts(solve() ? "yes" : "no");
    return 0;
}