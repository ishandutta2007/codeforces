#include <cstdio>

using namespace std;

int main()
{
    int n,i,v[100005],rasp=0;
    scanf("%d",&n);
    bool bun=false;

    for(i=0;i<n;i++)
       scanf("%d",&v[i]);
    for(i=0;i<n;i++)
    {
        if(v[i]==i)
            rasp++;
        else
        {
            if(v[v[i]]==i)
                bun=true;
        }
    }
    if(rasp<n)
    {
        rasp++;
        if(bun)
            rasp++;
    }
    printf("%d\n",rasp);
}