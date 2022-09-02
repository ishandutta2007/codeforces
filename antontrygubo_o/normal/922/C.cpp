#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n, k;
    cin>>n>>k;
    bool ok = true;
    long long i = 1;
    while ((ok)&&(i<=k))
    {
        if (n%i!=i-1) ok = false;
        i++;
    }
    if (ok) cout<<"Yes";
    else cout<<"No";
    
}