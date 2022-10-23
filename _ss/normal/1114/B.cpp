#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=int(2e5)+1;
struct dl
{
    long long vl,st;
};
dl a[maxn];
int n,m,k,check[maxn],b[maxn];
bool qt(dl t1, dl t2)
{
    return t1.vl>t2.vl;
}
int main()
{
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].vl;
        a[i].st=i;
        b[i]=a[i].vl;
    }
    sort(a+1,a+n+1,qt);
    long long s=0;
    for (int i=1;i<=m*k;i++)
    {
        check[a[i].st]=1;
        s=s+a[i].vl;
    }
    cout<<s<<endl;
    int t=0,t2=0;
    for (int i=1;i<=n;i++)
        if (check[i]==1)
        {
            t++;
            if (t==m)
            {
                cout<<i<<" ";
                t=0;
                t2++;
            }
            if (t2==k-1) break;
        }
    return 0;
}