#include <iostream>
#include <cstdio>

using namespace std;
const long double eps = 1e-6;
struct point{
    int x, y;
};
point a[10];
bool use[10];
point och1[10];
int och11[10];
point och2[10];
int och22[10];

bool check = false;
long double operator ^ (point a, point b){
    return a.x * b.x + a.y * b.y;
}
point operator - (point a, point b){
    point x;
    x.x = a.x - b.x;
    x.y = a.y - b.y;
    return x;
}

bool ygol (point b1, point a, point b2){
    if (((b2 - a) ^ (b1 - a)) < eps)
        return true;
    else
        return false;
}
long double len(point a){
    return a ^ a;
}

void prov(){
    bool check1 = true;
    int i;
    for (i = 1; i < 5; i++){
        if (! ygol(och1[i - 1], och1[i % 4], och1[(i + 1) % 4]))
            check1 = false;
    }
    for (i = 1; i < 5; i++){
        if (! ygol(och2[i - 1], och2[i % 4], och2[(i + 1) % 4]))
            check1 = false;
    }
    for (i = 0; i < 4; i++)
        if (len(och1[i] - och1[(i + 1) % 4]) != len(och1[(i + 1) % 4] - och1[(i + 2) % 4]))
            check1 = 0;
    if (len(och2[0] - och2[1]) != len(och2[3] - och2[2])|| len(och2[3] - och2[0]) != len(och2[1] - och2[2] ))
        check1 = 0;
    if (check1){
        check = true;
        printf("YES\n");
        for (i = 0; i < 4; i++)
            printf("%d ", och11[i] + 1);
        printf("\n");
        for (i = 0; i < 4; i++)
            printf("%d ", och22[i] + 1);


    }
}
void gen2(int k){
    int i;
    if (k == 4){
        if (! check)
            prov();
        return;
    }
    for (i = 0; i < 8; i++)
        if (! use[i]){
            use[i] = 1;
            och2[k] = a[i];
            och22[k] = i;
            gen2(k + 1);
            use[i] = 0;
        }
}

void gen(int k){
    int i;
    if (k == 4){
        gen2(0);
        return;
    }
    for (i = 0; i < 8; i++)
        if (! use[i]){
            use[i] = 1;
            och1[k] = a[i];
            och11[k] = i;
            gen(k + 1);
            use[i] = 0;
        }
}


int main()
{
   // freopen("in", "r", stdin);
   // freopen("out", "w", stdout);
    int i;
    for (i = 0; i < 8; i++)
        scanf("%d%d", &a[i].x, &a[i].y);
    gen(0);
    if (! check)
        printf("NO");
    return 0;
}