#include <bits/stdc++.h>
using namespace std;
const int N = 500005;

int n;
char a[N];

bool t[26];
int main()
{
    scanf(" %s", a);
    n = strlen(a);
    for (int i = 0; i < n; ++i)
    {
        bool z = false;
        for (int j = (a[i] - 'a') - 1; j >= 0; --j)
        {
            if (t[j])
            {
                z = true;
                break;
            }
        }
        if (z)
            printf("Ann\n");
        else
            printf("Mike\n");
        t[a[i] - 'a'] = true;
    }
    return 0;
}