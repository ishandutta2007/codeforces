#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char s[4][20000];
//a, e, i, o, u.
bool f(char ch){
    if (ch == 'a' || ch == 'o' || ch == 'e' || ch == 'i' || ch == 'u')
        return 1;
    return 0;
}
bool eq(int i, int j){
    int n1, n2, ii;
    n1 = strlen(s[i]);
    n2 = strlen(s[j]);
    if (n1 != n2)
        return 0;
    for (ii = 0; ii < n1; ii++)
        if (s[i][ii] != s[j][ii])
            return 0;
    return 1;
}
int main()
{
     bool b1 = 1, b2 = 1, b3 = 1;
    int n, k, i, j, n1, d, ii, jj;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++){
        memset(s, 0, sizeof s);
        for (j = 0; j < 4; j++){
            scanf("%s", s[j]);
            n1 = strlen(s[j]);
            d = 0;
            ii = n1 - 1;
            while (ii >= 0 && d < k){
                if (f(s[j][ii]))
                    d++;
                ii--;
            }
            ii++;
            if (d < k){
                printf("NO");
                return 0;
            }
            for (jj = ii; jj < n1; jj++)
                s[j][jj - ii] = s[j][jj];
            s[j][n1 - ii] = 0;

        }
        if (! (eq(0, 1) && eq(2, 3)))
            b1 = 0;
        if (! (eq(0, 2) && eq(1, 3)))
            b2 = 0;
        if (! (eq(2, 1) && eq(0, 3)))
            b3 = 0;
    }


    if (b1 && b2 && b3){
        printf("aaaa");
        return 0;
    }
    if (b1){
        printf("aabb");
        return 0;
    }
    if (b2){
        printf("abab");
        return 0;
    }
    if (b3){
        printf("abba");
        return 0;
    }
    printf("NO");

    return 0;
}