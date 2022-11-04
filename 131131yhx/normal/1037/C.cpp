#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <iostream>
#include <ctime>

using namespace std;

int n;

char ch[2][1000010];

signed main() {
    scanf("%d%s%s", &n, ch[0] + 1, ch[1] + 1);
    int ans = 0;
    for(int i = 1; i <= n; i++)
        if(ch[0][i] == '1' && ch[1][i] == '0') {
            if(ch[1][i - 1] == '1' && ch[0][i - 1] == '0') swap(ch[0][i], ch[0][i - 1]), ans++;
            else if(ch[1][i + 1] == '1' && ch[0][i + 1] == '0') swap(ch[0][i], ch[0][i + 1]), ans++;
        }
    for(int i = 1; i <= n; i++) if(ch[0][i] != ch[1][i]) ans++;
    printf("%d\n", ans);
    return 0;
}