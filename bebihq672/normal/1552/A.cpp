#include<bits/stdc++.h>
using namespace std;

char s[101];

int a[101], b[101];


int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);

        scanf("%s", s + 1);
        for(int i = 1; i <= n; i++)
            b[i] = a[i] = s[i] - 'a';
        sort(b + 1, b + n + 1);
        
        int ans = 0;
        for(int i = 1; i <= n; i++)
        if(b[i] != a[i])
            ans++;
        printf("%d\n", ans);
    }
    return 0;
}