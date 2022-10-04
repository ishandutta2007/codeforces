#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=200005;

int n,a[3];
void print(int x,int t)
{
	a[x]-=t;
	while(t--)printf("%d ",x); 
}

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int x;
    cin>>n;
    for(int i=1;i<=n;i++){cin>>x;++a[x];}
    if(!a[1] || !a[2])
    {
    	print(1,a[1]);
    	print(2,a[2]);
    }
    else
    {
    	print(2,1);
    	print(1,1);
    	print(2,a[2]);
    	print(1,a[1]);
    }
    return 0;
}