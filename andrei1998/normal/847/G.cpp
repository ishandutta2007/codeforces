#include <cstdio>
#include <algorithm>

using namespace std;

char sir[1010][8];

int main() 
{
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int n,sol=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("\n%s",sir[i]);
    for(int i=0;i<7;i++)
    {
        int nr=0;
        for(int j=1;j<=n;j++) nr+=sir[j][i]-'0';
        sol=max(sol,nr);
    }
    printf("%d",sol);
    return 0;
}