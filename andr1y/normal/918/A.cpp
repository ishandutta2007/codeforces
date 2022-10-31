#include <bits/stdc++.h>
#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
using namespace std;

int main()
{
    ll n, sk=2;
    cin >> n;
    ll fib[n+1] = {0};
    fib[0]=1;
    fib[1]=1;
    for(ll i=2;i<=n;i++)fib[i]=fib[i-1]+fib[i-2];
    cout << "O";
    for(ll i=2;i<=n;i++){
        if(fib[sk]==i){
            sk++;
            cout << "O";
        }else if(fib[sk]<i){sk++;cout << "o";}
        else if(fib[sk]>i) cout << "o";
    }
}