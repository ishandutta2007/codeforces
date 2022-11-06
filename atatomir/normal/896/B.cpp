#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 1024

int n, m, c, i, j, p;
int data[maxN];
int c2;

bool check() {
    int i;

    for (i = 1; i <= n; i++)
        if (data[i] == 0)
            return false;

    return true;
}

void add_left() {
    int i;

    for (i = 1; data[i] != 0 && data[i] <= p; i++);
    data[i] = p;
    printf("%d\n", i);
    fflush(stdout);
}

void add_right() {
     int i;

    for (i = n; data[i] != 0 && data[i] >= p; i--);
    data[i] = p;
    printf("%d\n", i);
    fflush(stdout);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &m, &c);
    c2 = c / 2;

    while (!check()) {
        scanf("%d", &p);
        if (p <= c2)
            add_left();
        else
            add_right();
    }


    return 0;
}