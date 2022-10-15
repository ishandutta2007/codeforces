#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int MAXL = 20;

int main()
{
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (1 < j ) printf(" ");
            
            int x = i * j;
            char s[MAXL];
            int l = 0;
            
            do s[l++] = x % n + '0'; while (x /= n);
            s[l] = 0;
            reverse(s, s + l);
            
            printf("%s", s);
        }
        printf("\n");
    }
    
    return 0;
}