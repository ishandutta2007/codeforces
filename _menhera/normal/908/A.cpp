#include<bits/stdc++.h>
using namespace std;
char a[10101];
int main()
{
    scanf("%s", a);
    int cnt = 0;
    for(int i=0; i<strlen(a); ++i)
    {
        if(a[i] == 'a' || a[i] == 'e' ||
        a[i] == 'i' || a[i] == 'o' ||
        a[i] == 'u' )
            ++cnt;
        if(a[i] == '1' || a[i] == '9' ||
        a[i] == '3' || a[i] == '7' ||
        a[i] == '5' )
            ++cnt;
    }
    printf("%d\n", cnt);
}