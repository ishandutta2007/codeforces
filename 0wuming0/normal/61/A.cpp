#include"bits/stdc++.h"
using namespace std;
int main()
{
    char s1[105],s2[105];
    scanf("%s%s",s1,s2);
    for(int i=0;s1[i];i++)
    {
        printf("%1d",s1[i]^s2[i]);
    }
    return 0;
}