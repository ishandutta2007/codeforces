#include<bits/stdc++.h>
 
#define ll long long 

using namespace std;

int n, k;

ll A[51][51] = {};

bool check(ll t)
{
    bool B[51][51] = {};
    for (int i = 0; i<=n; i++)
    for (int j = i; j<=n; j++)
    {
        if ((A[i][j]&t)==t) B[i][j] = true;
    }
    bool C[51][51] = {};
    for (int i = 0; i<=n; i++)
    {
        for (int j = 0; j<=i; j++)
        {
            if (B[j][i])
            {
                if (j==0) C[i][1] = true;
                else
                {
                    for (int x = 0; x<=j; x++) if (C[j-1][x]==true) C[i][x+1] = true;
                }
            }

        }
    }
    
    /*for (int i = 0; i<n; i++)
    {
        cout<<i<<": ";for (int j = 0; j<n; j++) cout<<B[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;
    for (int i = 0; i<n; i++)
    {
        cout<<i<<": ";for (int j = 0; j<n; j++) cout<<C[i][j]<<' ';
        cout<<endl;
    }*/
    return C[n-1][k];
}

vector<ll> deg;

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    ll a[n];
    for (int i = 0; i<n; i++) cin>>a[i];
    for (int i = 0; i<n; i++)
    {
        A[i][i] = a[i];
        for (int j = i+1; j<n; j++) A[i][j] = A[i][j-1]+a[j];
    }
    
    ll i = 1;
    while (i<1000000000000000000) i*=2;
    deg.push_back(i);
    while (i>1) {i/=2; deg.push_back(i);}
    ll res = 0;
    for (int j = 0; j<deg.size(); j++)
    {
        if (check(res+deg[j])) res+=deg[j];
    }
    
    cout<<res;

    
}