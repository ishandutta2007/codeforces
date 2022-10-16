#include <iostream>
#include <cstring>
#include <utility>
#include <list>

using namespace std;

int h[36020];

int main()
{
    char sir[4005];
    int a,n,i,j,suma,v[4005];

    cin>>a;
    cin.get();
    cin.get(sir+1,4005);
    n=strlen(sir+1);

    v[0]=0;
    for(i=1;i<=n;i++)
        v[i]=v[i-1]+(sir[i]-'0');

    for(i=1;i<=n;i++)
        for(j=i;j<=n;j++)
        {
            suma=v[j]-v[i-1];
            h[suma]++;
        }

    long long int rasp=0;
    for(i=1;i<=n;i++)
        for(j=i;j<=n;j++)
        {
            suma=v[j]-v[i-1];
            if(a==0)
            {
                if(suma==0)
                    rasp+=((n*(n+1))/2);
                else
                    rasp+=h[0];
            }
            else if(suma!=0)
                if(a%suma==0)
                    rasp+=(((a/suma)<36020)?h[a/suma]:0);
        }

    cout<<rasp<<'\n';
    return 0;
}