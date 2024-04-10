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

int n, m, q, i;
char S[maxN], T[maxN];

int s1[maxN], s2[maxN];
int last_Y1[maxN], last_Y2[maxN];
int l1, r1, l2, r2;

bool query() {
    int cnt_S = s1[r1] - s1[l1 - 1];
    int cnt_T = s2[r2] - s2[l2 - 1];

    if ( ((cnt_S ^ cnt_T) & 1) == 1 ) return false;
    if (cnt_S > cnt_T) return false;

    int fin_S = min(r1 - l1 + 1, r1 - last_Y1[r1]);
    int fin_T = min(r2 - l2 + 1, r2 - last_Y2[r2]);

    if (cnt_S == cnt_T) {
        //! you can not do any X move
        if (fin_S < fin_T) return false;
        if ((fin_S % 3) != (fin_T % 3)) return false;
        return true;
    } else {
        if (fin_S == fin_T && fin_S == r1 - l1 + 1) return false;

        if (fin_S >= fin_T) return true;
        return false;
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%s\n%s", S + 1, T + 1);
    n = strlen(S + 1);
    m = strlen(T + 1);

    for (i = 1; i <= n; i++) {
        s1[i] = s1[i - 1];
        last_Y1[i] = last_Y1[i - 1];
        if (S[i] != 'A') {
            s1[i]++;
            last_Y1[i] = i;
        }
    }

    for (i = 1; i <= m; i++) {
        s2[i] = s2[i - 1];
        last_Y2[i] = last_Y2[i - 1];
        if (T[i] != 'A') {
            s2[i]++;
            last_Y2[i] = i;
        }
    }

    scanf("%d", &q);
    for (i = 1; i <= q; i++) {
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);

        if (query())
            printf("1");
        else
            printf("0");
    }


    return 0;
}