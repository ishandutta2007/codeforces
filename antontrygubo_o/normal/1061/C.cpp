#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 1000000007;


//vector<vector<int>> a(100, vector<int>(a))


int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<ll> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];
    vector<ll> kek(n+1, 0);
    kek[1] = 1;
    for (int i = 1; i<n; i++)
    {
        for (int j = 1; j<sqrt(a[i]); j++) if (a[i]%j==0&&a[i]/j<=n) kek[a[i]/j]=(kek[a[i]/j - 1]+kek[a[i]/j])%p;
        for (int j = sqrt(a[i]); j>=1; j--) if (a[i]%j==0&&j<=n) kek[j]=(kek[j]+kek[j-1])%p;
        kek[1]++;
        //for (int i = 0; i<=n; i++) cout<<kek[i]<<' ';
        //cout<<endl;
    }
    ll summ = 0;
    for (int i = 0; i<=n; i++) summ+=kek[i];
    cout<<summ%p;
}