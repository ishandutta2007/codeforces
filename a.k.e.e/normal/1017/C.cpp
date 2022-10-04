#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005;

int n,a[MAXN];

int main()
{
    cin>>n;
    int m;
    for(m=1;m*m<=n;m++);
	if( ((n-1)/m+1+m)>((n-1)/(m-1)+m) )--m;
	for(int i=1;i<=n%m;i++)
		printf("%d ",n/m*m+i);
	n=n/m*m;
	for(int i=1;i*m<=n;i++)
		for(int j=1;j<=m;j++)
			printf("%d ",n-i*m+j);
    return 0;
}