#include <bits/stdc++.h>
#include<queue>
using namespace std;
typedef int ll;
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define _y1 dgkpothjoih
///--------------------------------------------------------------------------------------------------------------///
ll a[10000];
///--------------------------------------------------------------------------------------------------------------///

int main()
{
    ll n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    if (n==1)
    {
        if (a[1]==0) cout<<"UP"; else
        if (a[1]==15) cout<<"DOWN"; else cout<<-1;
    } else
    {
        if (a[n]==0) cout<<"UP"; else
        if (a[n]==15) cout<<"DOWN"; else
        if (a[n]>a[n-1]) cout<<"UP"; else cout<<"DOWN";
    }
}