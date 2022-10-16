#include <iostream>

using namespace std;

int frecv[105][105];

int main()
{
    int n,m,i,j,k,x;
    cin>>n;

    for(i=1;i<=n;i++)
    {
        cin>>m;
        for(j=0;j<m;j++)
        {
            cin>>x;
            frecv[i][x]=1;
        }
    }

    bool ok,str;
    for(i=1;i<=n;i++)
    {
        ok=true;
        str=true;
        for(j=1;j<=n;j++)
            if(j!=i)
            {
                str=true;
                for(k=1;k<105;k++)
                    if(frecv[j][k]==1 && frecv[i][k]==0)
                    {
                        str=false;
                        break;
                    }
                if(str==true)
                {
                    ok=false;
                    break;
                }

            }
        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

    return 0;
}