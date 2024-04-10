#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=200005;

int n,x[MAXN];

int main()
{
    cin>>n;
    int ans=1,a,b,c,d;
    for(int i=1;i<=n;i++)
    {
    	cin>>a>>b>>c>>d;
    	x[i]=a+b+c+d;
    	if(x[i]>x[1])ans++;
    }
    cout<<ans<<endl;
    return 0;
}