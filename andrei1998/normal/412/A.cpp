#include <iostream>

using namespace std;

int main()
{
    char sir[105];
    int n,k,i,cate;
    int dir=0;

    cin>>n>>k;
    cate=n;

    for(i=1;i<=n;i++)
        cin>>sir[i];

    while(cate)
    {
        if(sir[k]!=' ')
        {
            cout<<"PRINT "<<sir[k]<<'\n';
            sir[k]=' ';
            cate--;
        }
        else
        {
            if(dir==0)
            {
                if((k-1)<(n-k))
                    dir=-1;
                else
                    dir=1;
            }
            else
            {
                int nk=k+dir;

                if(!(nk>=1 && nk<=n))
                {
                    if(dir>0)
                        dir=-1;
                    else
                        dir=1;
                }
                else
                {
                    k=nk;
                    if(dir<0)
                        cout<<"LEFT\n";
                    else
                        cout<<"RIGHT\n";
                }
            }
        }
    }

    return 0;
}