#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;
const int MAXN=105;

int n;
ll a[MAXN],b[MAXN];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    	cin>>a[i];
    for(int i=1;i<=n;i++)
    	cin>>b[i];
    ll s=0,s2=0;
    for(int i=1;i<=n;i++)
    	s+=a[i],s-=b[i];
    if(s<0)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}