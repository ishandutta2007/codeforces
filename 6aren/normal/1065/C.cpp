#include <bits/stdc++.h>
using namespace std;
int a[200005],n,k,h[200005];

int main()
{
    cin >> n >> k;
    int mini=1000000009;
    int maxi=0;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        if (a[i]<mini) mini=a[i];
        if (a[i]>maxi) maxi=a[i];
        h[0]++;
        h[a[i]]--;
    }
    for (int i=1;i<=200004;i++)
    {
        h[i]=h[i-1]+h[i];
    }
    for (int i=5;i>=0;i--)
    {
        //cout << h[i] << endl;
    }
    int res=0;
    long long cost=0,stan=k;
    int i=200004;
    if (mini==maxi)
    {
        cout << 0;
        return 0;
    }
    res=1;
    while (i>=mini)
    {
        cost+=h[i];
        if (cost > stan)
        {
            res++;
            stan=cost-h[i]+k;
        }
        i--;
    }
    cout << res;
}