#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;
struct p{
    int x, y;
};
int a[200000];
int b[200000];
int c[200000];
int res[100000][3];
int q[10];
set < p > r;
bool operator < (p a, p b){
    if (a.x > b.x || (a.x == b.x && a.y > b.y))
        return 1;
    return 0;
}


int main()
{
   int n, i, uk, uk2, j;
    bool check;
    p p1, p2, p3;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    b[0] = 1;
    c[0] = a[0];
    uk = 0;
    for (i = 1; i < n; i++){
        if (a[i] != a[i - 1])
            uk++;
        b[uk]++;
        c[uk] = a[i];
    }
    if (uk < 2){
        printf("0");
        return 0;
    }
    for (i = 0; i <= uk; i++){
        p1.x = b[i];
        p1.y = c[i];
        r.insert(p1);
   //     cerr << r.size() << " ";
    }
    check = true;
    uk2 = 0;
    while (check){
        p1 = *r.begin();
        r.erase(r.begin());
        p2 = *r.begin();
        r.erase(r.begin());
        p3 = *r.begin();
        r.erase(r.begin());
        if (p3.x <= 0){
            check = false;
            continue;
        }
        p1.x--;
        p2.x--;
        p3.x--;
        q[0] = p1.y;
        q[1] = p2.y;
        q[2] = p3.y;
        r.insert(p1);
        r.insert(p2);
        r.insert(p3);
        sort(q, q + 3);
        res[uk2][0] = q[0];
        res[uk2][1] = q[1];
        res[uk2][2] = q[2];
        uk2++;
    }
    printf("%d\n", uk2);
    for (i = 0; i < uk2; i++){
        for (j = 2; j >= 0; j--)
            printf("%d ", res[i][j]);
        printf("\n");
    }

    return 0;
}