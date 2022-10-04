#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN=1005;

int n;
char s[MAXN];

int main()
{
    scanf("%d%s",&n,s+1);
    if((n==1 && s[1]=='0') || (s[1]=='0' && s[2]=='0') || (s[n]=='0' && s[n-1]=='0'))
    {
        printf("No\n");
        return 0;
    }
    for(int i=1;i<=n;i++)
        if((s[i]=='1' && s[i-1]=='1') || (s[i]=='0' && s[i-1]=='0' && s[i+1]=='0'))
        {
            printf("No\n");
            return 0;
        }
    printf("Yes\n");
    return 0;
}