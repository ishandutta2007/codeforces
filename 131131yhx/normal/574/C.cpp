#include<cstdio>

int C(int x)
{
    while(x % 2 == 0) x /= 2;
    while(x % 3 == 0) x /= 3;
    return x;
}
int main()
{
    int n;
    scanf("%d", &n);
    int k;
    scanf("%d", &k);
    int standard = C(k);
    for(int i = 2; i <= n; i++)
    {
        int s;
        scanf("%d", &s);
        if(C(s) != standard)
        {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}