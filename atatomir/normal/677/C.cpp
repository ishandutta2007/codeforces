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

#define maxN 100011
#define mod 1000000007LL

int n, i, j;
char s[maxN];
int how[70];

ll ans;

int get_code(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    if ('A' <= c && c <= 'Z') return 10 + c - 'A';
    if ('a' <= c && c <= 'z') return 36 + c - 'a';
    if ('-' == c) return 62;
    if ('_' == c) return 63;

    cerr << "Error";
}

int main()
{
    //freopen("test.in","r",stdin);

    for (i = 0; i < 64; i++)
        for (j = 0; j < 64; j++)
            how[ i & j ]++;

    scanf("%s", s + 1);
    n = strlen(s + 1);

    ans = 1;
    for (i = 1; i <= n; i++) {
        int id = get_code(s[i]);

        ans = (ans * how[id]) % mod;
    }

    printf("%lld", ans);

    return 0;
}