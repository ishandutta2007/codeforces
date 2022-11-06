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

#define maxN 111

vector<char> vow = {'a', 'e', 'i', 'u', 'o', 'y'};

int n, i, j;
int p[maxN];
char s[maxN];

bool match(char c) {
    for (auto e : vow)
        if (e == c)
            return true;
    return false;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &p[i]);
    scanf("\n");

    for (i = 1; i <= n; i++) {
        memset(s, 0, sizeof(s));
        gets(s + 1);

        for (j = 1; j <= 100; j++)
            if (match(s[j]))
                p[i]--;

        if (p[i] != 0) {
            printf("NO");
            exit(0);
        }
    }

    printf("YES");


    return 0;
}