#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
pll get(int ab){
    if(ab == 32) return {4, 8};
    if(ab == 60) return {4, 15};
    if(ab == 64) return {4, 16};
    if(ab == 92) return {4, 23};
    if(ab == 168) return {4, 42};
    if(ab == 120) return {8, 15};
    if(ab == 128) return {8, 16};
    if(ab == 184) return {8, 23};
    if(ab == 336) return {8, 42};
    if(ab == 240) return {15, 16};
    if(ab == 345) return {15, 23};
    if(ab == 630) return {15, 42};
    if(ab == 368) return {16, 23};
    if(ab == 672) return {16, 42};
    if(ab == 966) return {23, 42};
}
int msq(int a){
    int i = 1;
    while(i*i<a) i++;
    return i;
}
int a[6];
main(){
    int ab, cd, bc, e;
    printf("? 1 2\n"); fflush(stdout); scanf("%d", &ab);
    printf("? 2 3\n"); fflush(stdout); scanf("%d", &bc);
    printf("? 3 4\n"); fflush(stdout); scanf("%d", &cd);
    printf("? 5 5\n"); fflush(stdout); scanf("%d", &e);
    pll gab = get(ab);
    pll gcd = get(cd);
    pll gbc = get(bc);
    if(gab.x == gbc.x){
        a[0] = gab.y;
        a[1] = gab.x;
        a[2] = gbc.y;
    }else if(gab.x == gbc.y){
        a[0] = gab.y;
        a[1] = gbc.y;
        a[2] = gbc.x;
    }else if(gab.y == gbc.x){
        a[0] = gab.x;
        a[1] = gbc.x;
        a[2] = gbc.y;
    }else if(gab.y == gbc.y){
        a[0] = gab.x;
        a[1] = gbc.y;
        a[2] = gbc.x;
    }
    a[3] = cd/a[2];
    a[4] = msq(e);
    a[5] = 7418880/(a[0]*a[1]*a[2]*a[3]*a[4]);
    printf("! %d %d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4], a[5]);fflush(stdout);
    return 0;
}