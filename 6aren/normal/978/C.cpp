#include <bits/stdc++.h>
using namespace std;
long long  a[200001], b[200001], c[200001],nha[200001],phong[200001], i, j, n ,m, u, v;
int main()
{
    cin >> n; cin >> m;
    for (i=0;i<=n-1;i++)
    {
        cin >> a[i];
    }
    for (i=0;i<=m-1;i++)
    {
        cin >> b[i];
    }
    c[0]=0;c[1]=a[0];
    for (i=2;i<=n;i++)
    {
        c[i]=c[i-1]+a[i-1];
    }
    u=0;v=0;
    for (i=0;i<=m+n;i++)
    {
        if (b[u]<=c[v])
        {
            nha[u]=v;phong[u]=b[u]-c[v-1];
            u++;

        }
        else
        {
            v++;
        }
    }

        for (i=0;i <=m-1; i++)
        {
            cout << nha[i] << " " << phong[i] << endl;
        }

}