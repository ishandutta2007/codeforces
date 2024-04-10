#include <bits/stdc++.h>
using namespace std;
const int N = 202;

int n;
char aa[N];
char a[N];

vector<int> v;
void gor(int i)
{
    if (a[i] == 'B')
        a[i] = 'W';
    else
        a[i] = 'B';
    if (a[i + 1] == 'B')
        a[i + 1] = 'W';
    else
        a[i + 1] = 'B';
    v.push_back(i + 1);
}

bool stg(char u)
{
    v.clear();
    for (int i = 0; i < n; ++i)
        a[i] = aa[i];
    int i = -1;
    while (1)
    {
        if (i == n - 1)
            return true;
        if (a[i + 1] == u)
        {
            ++i;
            continue;
        }
        if (i + 1 == n - 1)
            return false;
        gor(i + 1);
        ++i;
    }
}

int main()
{
    scanf("%d", &n);
    scanf(" %s", a);
    for (int i = 0; i < n; ++i)
        aa[i] = a[i];
    if (stg('B'))
    {
        printf("%d\n", v.size());
        for (int i = 0; i < v.size(); ++i)
            printf("%d ", v[i]);
        return 0;
    }
    else if (stg('W'))
    {
        printf("%d\n", v.size());
        for (int i = 0; i < v.size(); ++i)
            printf("%d ", v[i]);
        return 0;
    }
    printf("-1\n");
    return 0;
}