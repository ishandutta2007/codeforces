#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
const ll maxn=2e5+5;
int n,b[maxn],c[maxn];
pii a[maxn];
int main()
{
    int x;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>x;
        a[i]={x,i};
    }
    sort(a+1,a+n+1);
    for (int i=1;i<n;i++) b[i]=a[i+1].fi-a[i].fi;
    int kt=1;
    for (int i=2;i<n-1;i++)
        if (b[i]!=b[i+1]) kt=0;
    if (kt)
    {
        cout<<a[1].se;
        exit(0);
    }
    kt=1;
    for (int i=1;i<n-2;i++)
        if (b[i]!=b[i+1]) kt=0;
    if (kt) cout<<a[n].se,exit(0);
    int flag=1,mark;
    kt=1;
    for (int i=1;i<n;i++) c[i]=b[i];
    for (int i=1;i<n-1;i++)
        if (b[i]!=b[i+1])
        {
            if (flag)
            {
                flag=0;
                b[i+2]+=b[i+1];
                b[i+1]=b[i];
                mark=i+2;
            }
            else kt=0;
        }
    if (kt) cout<<a[mark].se,exit(0);
    for (int i=1;i<n;i++) b[i]=c[i];
    b[2]+=b[1];
    kt=1;
    for (int i=2;i<n-1;i++)
        if (b[i]!=b[i+1]) kt=0;
    if (kt) cout<<a[2].se; else cout<<-1;
    //for (int i=1;i<n;i++) cout<<b[i]<<" ";
    return 0;
}