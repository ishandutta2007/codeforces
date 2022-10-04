#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
ll n,m,k;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int main()
{
    cin>>n>>m>>k;
    if(n*m*2%k || k==1)return 0*printf("NO\n");
    printf("YES\n");
    ll t=gcd(n,k);
    if(t==1)m*=2;
    else n*=2;
    t=gcd(n,k);
    n/=t;k/=t;m/=k;
    cout<<"0 0\n"<<n<<" 0\n"<<n<<" "<<m<<endl;
    return 0;
}