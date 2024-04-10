#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;
const int MAXN=100005;

int n;
char a[MAXN],b[MAXN];

int main()
{
    scanf("%d%s%s",&n,a,b);
    ll c0=0,c1=0,s0=0,s1=0;
    for(int i=0;i<n;i++)
    {
    	if(a[i]=='0')s0++;
    	else s1++;
    	if(b[i]=='0')
    	{
    		if(a[i]=='0')c0++;
    		else c1++;
    	}
    }
    cout<<s0*c1+s1*c0-c0*c1<<endl;
    return 0;
}