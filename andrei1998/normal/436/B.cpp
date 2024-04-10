#include <iostream>
#include <cstring>

using namespace std;

int col[2005];
char sir[2005];

int main()
{
    int n,m,k,i,j;

    cin>>n>>m>>k;

    for(i=1;i<=n;i++)
    {
        cin.get();
        cin.get(sir+1,2005);

        for(j=1;j<=m;j++)
            if(sir[j]=='U' && (i&1))
                col[j]++;
            else if(sir[j]=='L')
            {
                if((j-i+1)>=1)
                    col[j-i+1]++;
            }
            else if(sir[j]=='R')
            {
                if((j+i-1)<=m)
                    col[j+i-1]++;
            }
    }

    cout<<col[1];
    for(j=2;j<=m;j++)
        cout<<' '<<col[j];
    cout<<'\n';

    return 0;
}