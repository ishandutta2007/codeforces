#include <iostream>

#define lint long long int
using namespace std;

lint mat[2005][2005];
lint ss[2005][2005];
lint sf[2005][2005];
lint fs[2005][2005];
lint ff[2005][2005];

int main()
{
    ios_base::sync_with_stdio(false);

    int n=0;
    cin>>n;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>mat[i][j];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            ss[i][j]=mat[i][j]+ss[i-1][j-1];

    for(int i=1;i<=n;i++)
        for(int j=n;j>=1;j--)
            sf[i][j]=mat[i][j]+sf[i-1][j+1];

    for(int i=n;i>=1;i--)
        for(int j=1;j<=n;j++)
            fs[i][j]=mat[i][j]+fs[i+1][j-1];

    for(int i=n;i>=1;i--)
        for(int j=n;j>=1;j--)
            ff[i][j]=mat[i][j]+ff[i+1][j+1];

    int l1,c1;
    int l2,c2;
    lint max1=-1;
    lint max2=-1;
    lint aux1;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if((i+j)&1){
                aux1=ss[i][j]+sf[i][j]+fs[i][j]+ff[i][j]-3ll*mat[i][j];
                if(aux1>max1){
                    max1=aux1;
                    l1=i;
                    c1=j;
                }
            }
            else{
                aux1=ss[i][j]+sf[i][j]+fs[i][j]+ff[i][j]-3ll*mat[i][j];
                if(aux1>max2){
                    max2=aux1;
                    l2=i;
                    c2=j;
                }
            }

    cout<<max1+max2<<'\n';
    cout<<l1<<' '<<c1<<' '<<l2<<' '<<c2<<'\n';

    return 0;
}