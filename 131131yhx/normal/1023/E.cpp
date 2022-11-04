#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cstdlib>
#include <bitset>
#include <string>

using namespace std;

vector <int> V1, V2;

int n;

int ask(int a, int b, int c, int d) {
    if(a <= 0 || b <= 0 || c > n || d > n) return 0;
    printf("? %d %d %d %d\n", a, b, c, d);
    fflush(stdout);
    char ch[5];
    scanf("%s", ch);
    return ch[0] == 'Y' ? 1 : 0;
}

int main() {
    scanf("%d", &n);
    int r1 = 1, c1 = 1, r2 = n, c2 = n;
    while(r2 + c2 != n + 1) {
        if(ask(r1, c1, r2, c2 - 1)) c2--, V2.push_back(0); else r2--, V2.push_back(1);
    }
    
    r2 = n, c2 = n;
    while(r1 + c1 != n + 1) {
        if(ask(r1 + 1, c1, r2, c2)) r1++, V1.push_back(1); else c1++, V1.push_back(0);
    }
    printf("! ");
    for(int i = 0; i < V1.size(); i++) putchar(V1[i] ? 'D' : 'R');
    for(int i = (int) V2.size() - 1; i >= 0; i--) putchar(V2[i] ? 'D' : 'R');
    fflush(stdout);
    return 0;
}