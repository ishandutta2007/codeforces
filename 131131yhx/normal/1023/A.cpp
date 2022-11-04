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

char ch[333333], S[333333];

int main() {
    int n, m;
    scanf("%d%d%s%s", &n, &m, ch + 1, S + 1);
    int w = -1;
    for(int i = 1; i <= n; i++) if(ch[i] == '*') {
        w = i;
        break;
    }
    if(w == -1) {
        bool ans = 1;
        if(n != m) ans = 0;
        for(int i = 1; i <= n; i++) if(ch[i] != S[i]) {
            ans = 0;
            break;
        }
        puts(ans ? "YES" : "NO");
    } else {
        bool ans = 1;
        if(n > m + 1) ans = 0; else {
            for(int i = 1; i < w; i++) if(ch[i] != S[i]) {
                ans = 0;
                break;
            }
            for(int i = w + 1; i <= n; i++) if(ch[i] != S[i - n + m]) {
                ans = 0;
                break;
            }
        }
        puts(ans ? "YES" : "NO");
    }
    return 0;
}