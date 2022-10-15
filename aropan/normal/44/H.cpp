#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 55;

char s[MAXN];
long long f[MAXN][10];
int n, m;

int main()
{
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/
    gets(s);
    n = strlen(s);
    
    for (int i = 0; i < 10; i++)
        f[0][i] = 1;
        
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < 10; j++)
        {
            int x = j + s[i + 1] - '0';
            f[i + 1][x / 2] += f[i][j];
            if (x % 2) f[i + 1][(x + 1) / 2] += f[i][j];
        }
    
    
    long long ans = 0;
    for (int i = 0; i < 10; i++)
        ans += f[n - 1][i];


    ans--;
    for (int i = 0; i < n - 1; i++)
        if (
            s[i] - '0' != (s[i] - '0' + s[i + 1] - '0') / 2 &&
            s[i] - '0' != (s[i] - '0' + s[i + 1] - '0' + 1) / 2)
        {
            ans++;
            break;
        }
    cout << ans << endl;
    return 0;
}