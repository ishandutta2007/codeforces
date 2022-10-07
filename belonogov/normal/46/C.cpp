#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

string s;
int a[100000];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, num = 0, ans = 1000000000;
    scanf("%d", &n);
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'H')
        {
            a[i + 1] = 1;
            a[i + n + 1] = 1;
            num++;
        }
            else
        {
            a[i + 1] = 0;
            a[i + n + 1] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int ans1 = 0;
        for (int j = 0; j < num; j++)
        {
            if (a[i + j] == 0) ans1++;
        }
        if (ans1 < ans) ans = ans1;
    }
    printf("%d", ans);
}