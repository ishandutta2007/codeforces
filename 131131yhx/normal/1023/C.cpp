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

typedef long long ll;

int n, k;

char ch[555555];

int lev = 0, cnt = 0;

int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", ch + 1);
    k /= 2;
    for(int i = 1; i <= n; i++)
        if(ch[i] == '(') {
            lev++;
            putchar('(');
            if(++cnt == k) {
                for(int j = 1; j <= lev; j++) putchar(')');
                return 0;
            }
        } else lev--, putchar(')');
    return 0;
}