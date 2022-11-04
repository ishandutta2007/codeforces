#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <bitset>

using namespace std;

char ch[200010];

int n;

vector <int> V[200010];

int t = 0, s = 0;

int main() {
    scanf("%s", ch + 1);
    n = strlen(ch + 1);
    for(int i = 1; i <= n; i++)
        if(ch[i] == '0') {
            if(t) {
                V[t].push_back(i);
                t--;
            } else V[++s].push_back(i);
        } else {
            if(t == s) {
                puts("-1");
                return 0;
            } else V[++t].push_back(i);
        }
    if(t) puts("-1"); else {
    printf("%d\n", s);
    for(int i = 1; i <= s; i++) {
        printf("%d ", V[i].size());
        for(int j = 0; j < V[i].size(); j++)
            printf("%d ", V[i][j]);
        putchar('\n');
    }}
    return 0;
}