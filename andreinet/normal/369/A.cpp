#include <cstdio>

using namespace std;

int main()
{
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    int n, m, k, sol=0, i, x;
    scanf("%d%d%d", &n, &m, &k);
    for(i=1;i<=n;i++)
    {
        scanf("%d", &x);
        if(x==1)
        {
            if(!m) sol++;
            else m--;
        }
        else
        {
            if(!k)
            {
                if(!m) sol++;
                else m--;
            }
            else k--;
        }
    }
    printf("%d", sol);
}