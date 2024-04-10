#include <bits/stdc++.h>
using namespace std;
int a[200005],vitri0[200005],trthai[200005];
int main()
{
    int n,i,t,vtam,ssa,sammax,check;
    cin >> n;
    ssa=0;sammax=-1000000001;t=1; check=1;
    for (i=1;i<=n;i++)
    {
        cin >> a[i];
        trthai[i]=0;
        if (a[i]<0) ssa++;
        if (a[i]<0 && a[i]>sammax)
        {
            vtam=i;
            sammax=a[i];
        }
    }
    if (ssa%2==1)
    {
        a[vtam]=0;
    }
    for (i=1;i<=n;i++)
        {
            if (a[i]==0)
            {
               vitri0[t]=i;
               t++;
            }
        }
    t--;
    int dem=0;
    for (i=1;i<=t-1;i++)
    {
        cout << 1 << " " << vitri0[i] << " " << vitri0[i+1] << endl;
        trthai[vitri0[i]]=1;trthai[vitri0[i+1]]=1;
    }
        if (t!=n && t!=0) {cout << 2 << " " << vitri0[t] << endl;}
        trthai[vitri0[t]]=1;
        int tt=1;
        for (i=1;i<=n-t-1;i++)
        {
            while (trthai[tt]==1) tt++;
            if (dem<=n-2) cout << 1 << " " << tt << " ";
            tt++;
            while (trthai[tt]==1) tt++;
            if (dem<=n-2) cout << tt << endl;
            dem++;
        }
}