#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 2000011

int n, i;
char A[maxN];
char B[maxN];
char work[maxN];
unordered_map<char, char> M;
int pr[maxN];
int q;

void reverse(char *v) {
    M['W'] = 'E';
    M['E'] = 'W';
    M['S'] = 'N';
    M['N'] = 'S';

    for (int i = 1; i <= n; i++)
        v[i] = M[ v[i] ];

    int i = 1;
    int j = n;
    while (i < j) swap(v[i++], v[j--]);
}

void combine(char *v1, char *v2, char *rez) {
    for (int i = 1; i <= n; i++)
        rez[i + n] = v1[i];
    for (i = 1; i <= n; i++)
        rez[i] = v2[i];


    //cerr << rez + 1 << '\n';
}

void kmp_pr() {
    q = 0;
    pr[1] = 0;

    for (i = 2; i <= n; i++) {
        while (q > 0 && work[q + 1] != work[i])
            q = pr[q];
        if (work[q + 1] == work[i])
            q++;
        pr[i] = q;
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d\n%s\n%s\n", &n, A + 1, B + 1);
    n--;
    reverse(B);
    combine(A, B, work);
    n <<= 1;
    kmp_pr();

    if (pr[n] == 0)
        printf("YES");
    else
        printf("NO");

    return 0;
}