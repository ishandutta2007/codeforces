#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

int n;

map <int, int> hsh;

int main() {
    scanf("%d", &n);
    int l = 1, r = 1e9 - 1;
    printf("10000 %d\n", r);
    fflush(stdout);
    r--;
    char c[7];
    scanf("%s", c);
    n--;
    while(n--) {
        int md = (l + r) / 2;
        /*if(l > r) {
            printf("10001 %d\n", l);
            fflush(stdout);
            char ch[7];
            scanf("%s", ch);
            if((ch[0] == c[0]) == (hsh[l])) printf("9999 %d 10002 %d\n", l - 1, l);
            else printf("9999 %d 10002 %d", l - 1, l + 1);
            return 0;
        }*/
        printf("10000 %d\n", md);
        fflush(stdout);
        char ch[7];
        scanf("%s", ch);
        if(ch[0] == c[0]) r = md - 1, hsh[md] = 1; else l = md + 1, hsh[md] = 0;
    }
    printf("9999 %d 10001 %d\n", l - 1, l);
    return 0;
}