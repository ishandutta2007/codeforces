#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>


using namespace std;
struct round1{
    int x, y, r;
};

round1 a[10000];
int sqr(int x){
    return x * x;
}

bool dist(round1 q, int x, int y){
    if (sqr(q.r) >= sqr(q.x - x) + sqr(q.y - y))
        return true;
    return false;
}


int main()
{
    int n, i, x1, x2, y1, y2, ans = 0, j;
    bool check;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].r);
    if (x2 < x1)
        swap(x1, x2);
    if (y2 < y1)
        swap(y1, y2);
    for (i = x1; i < x2; i++){
        check = true;
        for (j = 0; j < n; j++)
            if (dist(a[j], i, y1))
                check = false;
        if (check)
            ans++;
    }
    for (i = x2; i > x1; i--){
        check = true;
        for (j = 0; j < n; j++)
            if (dist(a[j], i, y2))
                check = false;
        if (check)
            ans++;
    }
    for (i = y1; i < y2; i++){
        check = true;
        for (j = 0; j < n; j++)
            if (dist(a[j], x2, i))
                check = false;
        if (check)
            ans++;
    }
    for (i = y2; i > y1; i--){
        check = true;
        for (j = 0; j < n; j++)
            if (dist(a[j], x1, i))
                check = false;
        if (check)
            ans++;
    }
    printf("%d", ans);

    return 0;
}