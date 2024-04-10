#include <iostream>
#include <cstdio>
#include <cstring>


using namespace std;

int a[1000];
int b[1000];
char s[200000];
char p[200000];

bool check(){
    int i;
    int s = 'a';
    int f = 'z';
    bool q = true;
    for (i = s; i <= f; i++)
        if (a[i] > b[i])
            q = false;

    return q;

}

int main()
{
    int i, n, m, ans = 0;
    scanf("%s", s);
    scanf("%s", p);
    n = strlen(s);
    m = strlen(p);
    for (i = 0; i < m; i++)
        if (p[i] != '?')
            b[(int)p[i]]++;

    for (i = 0; i < m; i++)
        if (s[i] != '?')
            a[(int)s[i]]++;

    for (i = 0; i <= n - m ; i++){
        if (check())
            ans++;
        if (s[i] != '?')
            a[(int)s[i]]--;
        if (s[i + m] != '?')
            a[(int)s[i + m]]++;
    }
    printf("%d", ans);
    return 0;
}