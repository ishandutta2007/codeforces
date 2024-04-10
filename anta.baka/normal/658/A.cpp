#include <stdio.h>
#include <algorithm>
using namespace std;
int p[50], t[50];
int main() {
    int n, c;
    scanf("%d%d", &n, &c);
    for(int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &t[i]);
    int ct = 0, s1 = 0;
    for(int i = 0; i < n; i++) {
        ct += t[i];
        s1 += max(0, p[i] - ct * c);
    }
    ct = 0;
    int s2 = 0;
    for(int i = n-1; i >= 0; i--) {
        ct += t[i];
        s2 += max(0, p[i] - ct * c);
    }
    if(s1 > s2)
        printf("Limak");
    else if(s1 < s2)
        printf("Radewoosh");
    else
        printf("Tie");
    return 0;
}