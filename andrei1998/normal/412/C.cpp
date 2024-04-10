#include <iostream>
#include <string>

using namespace std;

string v[100005];

int main()
{
    bool fixat;
    char cine;

    int n,i,m,j;

    cin>>n;
    for(i=1;i<=n;i++)
        cin>>v[i];

    m=v[1].size();
    for(i=0;i<m;i++)
    {
        fixat=false;
        cine='a';

        for(j=1;j<=n;j++)
        {
            if(v[j][i]!='?')
            {
                if(!fixat)
                {
                    fixat=true;
                    cine=v[j][i];
                }
                else if(fixat && v[j][i]!=cine)
                {
                    cine='?';
                    break;
                }
            }
        }

        cout<<cine;
    }
    cout<<'\n';

    return 0;
}