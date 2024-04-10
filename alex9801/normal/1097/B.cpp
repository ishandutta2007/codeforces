#include <bits/stdc++.h>

using namespace std;

int arr[20];
int n;

int s;
bool f(int x)
{
    if(x == n)
    {
        if((s % 360 + 360) % 360 == 0)
            return 1;
        return 0;
    }

    s += arr[x];
    if(f(x + 1))
        return 1;
    s -= 2 * arr[x];
    if(f(x + 1))
        return 1;
    s += arr[x];

    return 0;
}

int main()
{
    int i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if(f(0))
        puts("YES");
    else
        puts("NO");

    return 0;
}