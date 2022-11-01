#include <cstdio>
#include <cstring>

using namespace std;

char a[5005];

int main()
{
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    int n, i, sol=0, poz=0;
    fgets(a+1, 5005, stdin);
    n=strlen(a+1)-1;
    for(i=4;i<=n;i++)
    {
        if(a[i]=='r'&&a[i-1]=='a'&&a[i-2]=='e'&&a[i-3]=='b')
        {
            poz=i-3;
        }
        if(poz) sol+=poz;
    }
    printf("%d", sol);
}