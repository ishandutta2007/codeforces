#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
using namespace std;

const int MAXN = 1000005;

const char op[] = "<([{";
const char cl[] = ">)]}";

char s[MAXN];
stack <char> S;

void bye() {
    puts("Impossible");
    exit(0);
}

int find_op(char c) {
    for (int i = 0; i < 4; i++)
        if (op[i] == c) return i;
    return -1;
}

int find_cl(char c) {
    for (int i = 0; i < 4; i++)
        if (cl[i] == c) return i;
    return -1;
}

int main() {
    scanf("%s", s);
    
    int sol = 0;
    for (int i = 0; s[i]; i++) 
        if (find_op(s[i]) != -1) 
            S.push(s[i]);
        else {
            if (S.empty()) bye();
            sol += find_cl(s[i]) != find_op(S.top());
            S.pop();
        }
    
    if (!S.empty()) bye();
    printf("%d\n", sol);
    
    return 0;
}