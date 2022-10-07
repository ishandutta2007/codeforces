#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 2e5 + 2;
const int inf = 1e7;
char s[maxn];
int a[maxn];
int b[maxn];
pair <int, int> d[maxn];
int n;
// a, e, i, o, u
bool f (char ch){
    if (ch > 'z' || ch < 'a')
        ch -= 'A' - 'a';
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
    return false;
}

int binr(pair <int, int> x){
    int l = 0;
    int r = n;
    while (r - l > 1){
        if (d[(l + r) / 2] < x)
            l = (l + r) / 2;
        else
            r = (l + r) / 2;
    }
    return l;
}


int main()
{
   // freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int i, ans, res, k, ar, br, y;
    scanf("%s", s);
    n = strlen(s);
    if (f(s[0]))
        a[0] = 1;
    else
        b[0] = 1;
    for (i = 0; i < n; i++){
        a[i] = a[i - 1];
        b[i] = b[i - 1];
        if (f(s[i]))
            a[i]++;
        else
            b[i]++;
    }
    if (a[n - 1] == n){
        printf("No solution");
        return 0;
    }

    if (a[n - 1] <=  b[n - 1] * 2){
        printf("%d 1", n);
        return 0;
    }
    for (i = 0; i < n; i++){
        d[i].first = a[i] - b[i] * 2;
        d[i].second = i;
    }
    sort(d, d + n);
    ans = -1;
    for (i = 0; i < n; i++){
        y = 0;
        if (i)
            y = (a[i - 1] - b[i - 1] * 2);
        k = binr(make_pair(y, inf));
        if (d[k].first == y)
            ans = max(ans, d[k].second - i + 1);
    }
    res = 0;
    for (i = 0; i <= n - ans; i++){
        ar = a[ans - 1 + i];
        if (i)
            ar -= a[i - 1];
        br = b[ans - 1 + i];
        if (i)
            br -= b[i - 1];
        if (ar <= br * 2)
            res++;
    }
    printf("%d %d", ans, res);
    return 0;
}