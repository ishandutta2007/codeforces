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

#define maxN 555

int n, i;
char s[maxN];
char act = 'a' - 1;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%s", s + 1);
    n = strlen(s + 1);

    for (i = 1; i <= n; i++) {
         if (s[i] > act + 1) {
            printf("NO");
            return 0;
         }

         act = max(act, s[i]);
    }

    printf("YES");



    return 0;
}