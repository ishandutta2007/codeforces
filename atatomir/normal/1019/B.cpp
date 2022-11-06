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

const int maxN = 200011;

int n, i, l, r, mid, aux;
int v[maxN];
bool asked[maxN];
bool s1, s2, ss;

int ask(int x) {
    if (asked[x]) return v[x];
    printf("? %d\n", x);
    fflush(stdout);
    scanf("%d", &v[x]);
    asked[x] = true;
    return v[x];
}

bool get_sign(int x) {
    int aux = ask(x) - ask(x + n);
    if (aux == 0) {
        printf("! %d\n", x);
        exit(0);
    }

    if (aux < 0) return false;
    return true;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n); n /= 2;
    l = 1; r = n;

    aux = abs(ask(1) - ask(1 + n));
    if (aux % 2 == 1) {
        printf("! -1\n");
        return 0;
    }

    get_sign(l);
    get_sign(r);

    while (r - l >= 2) {
        s1 = get_sign(l);
        s2 = get_sign(r);

        if (s1 == s2) cerr << "Err";

        mid = (l + r) >> 1;
        ss = get_sign(mid);

        if (s1 == ss)
            l = mid;
        else
            r = mid;
    }

    printf("! -1\n");

    return 0;
}