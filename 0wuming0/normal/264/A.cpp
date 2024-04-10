#include"bits/stdc++.h"
using namespace std;
char s[1000005];
void solve(int i)
{
    if(s[i])
    {
        if(s[i]=='r')
        {
            printf("%d\n",i);
            solve(i+1);
        }
        else
        {
            solve(i+1);
            printf("%d\n",i);
        }
    }
}
int main()
{
    scanf("%s",s+1);
    solve(1);
    return 0;
}