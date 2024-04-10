#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n,m;
int a[105];
int b[105];

int din[105][105];

int main()
{
    int i,j;

    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];

    cin>>m;
    for(i=1;i<=m;i++)
        cin>>b[i];

    sort(a+1,a+n+1);
    sort(b+1,b+m+1);

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            din[i][j]=max(din[i-1][j],din[i][j-1]);

            if(abs(a[i]-b[j])<=1)
                din[i][j]=max(din[i][j],1+din[i-1][j-1]);
        }

    cout<<din[n][m];
    return 0;
}