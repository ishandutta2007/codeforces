#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    if (m >= n && k >= n)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}