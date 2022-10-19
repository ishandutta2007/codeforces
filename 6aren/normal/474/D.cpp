#include <bits/stdc++.h>
using namespace std;
int t,k,maxi; int f[100001],p[100001];int a[100001][3];
void init()
{
    cin >> t >> k;maxi=1;
    for (int i=1;i<=t;i++)
    {
        cin >> a[i][1] >> a[i][2];
        if (a[i][2]>maxi) maxi=a[i][2];
    }
}
void optimize()
{

    f[0]=1;p[0]=1;
    for (int j=1;j<=maxi;j++)
    {
        if (j<k) f[j]=f[j-1];
        else f[j]=(f[j-1]+f[j-k]) % (1000000007);
        p[j]=(p[j-1]+f[j])%1000000007;

    }

}

void printresult(int i)
{
    int t=(p[a[i][2]]-p[a[i][1]-1])%1000000007;
    if (t<0) t=1000000007+t;
    cout << t << endl;
}
int main()
{
    init(); optimize();
    for (int i=1;i<=t;i++)
    {
        printresult(i);
    }
}