#include <iostream>
#include <cstdio>
#include <cmath>
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
#define ll long long
#define endl "\n"
using namespace std;

string s[401],s1,s2,s3,s4;
ll mx,sc,m,n,i,j,l,r,x,a[1000001],d,c,ans;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    mx=-1e10;
    for(i=1;i<=n;i++)a[i]=1;
    for(i=2;i<=sqrt(n)+1
    ;i++)
    {
        sc=2;
        j=i*i;
        while(j<=n+1)a[j-1]=2,sc=3,j=j+i;
        mx=max(sc-1,mx);
    }
    cout << mx << endl;
    for(i=1;i<=n;i++)cout << a[i] << " ";
    return 0;
}