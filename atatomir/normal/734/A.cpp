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

int n, i;
char s[maxN];
int c[2];

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d\n%s", &n, s + 1);
    for (i = 1; i <= n; i++)
        if (s[i] == 'A')
            c[0]++;
        else
            c[1]++;

    if (c[0] > c[1])
        printf("Anton");
    if (c[0] < c[1])
        printf("Danik");

    if (c[0] == c[1])
        printf("Friendship");


    return 0;
}