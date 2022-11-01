#include <bits/stdc++.h>
using namespace std;
#define N (101*1000)
#define ll long long

ll n,k,p;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k>>p;
    while(p--)
    {
        ll a;
        cin>>a;
        if(k==n){cout<<'X';continue;}
        if(k*2>=n)
        {
            if(n%2 && k && a==n){cout<<'X';continue;}
            if(a%2)cout<<((a/2<n-k)?'.':'X');
            else cout<<'X';
        }   
        else
        {
            if(n%2)
            {
                if(k && a==n)cout<<'X';
                else
                {
                    if(a<=n-1-(k-1)*2)cout<<'.';
                    else cout<<(((a-n+1+(k-1)*2)%2)?'.':'X');
                }
            }
            else
            {
                if(a<=n-k*2)cout<<'.';
                else cout<<(((a-n+k*2)%2)?'.':'X');
            }
        }
    }
    return 0;
}