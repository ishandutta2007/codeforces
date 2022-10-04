#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
const int MAXN=100005;

ll ans=0;
int n,a[MAXN],b[MAXN];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
    for(int i=1;i<=n;i++)
    {
    	int t=min(a[i],b[i])-max(a[i-1],b[i-1])+1;
    	if(a[i]==b[i])--ans;
    	if(t>=0)ans+=t;
    }
    if(a[n]==b[n])++ans;
    cout<<ans<<endl;
    return 0;
}