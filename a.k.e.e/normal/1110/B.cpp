#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005;

int n,m,k;
int b[MAXN];

int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    	cin>>b[i];
    int sum=b[n]-b[1]+1;
    for(int i=n;i>1;i--)
    	b[i]-=b[i-1]+1;
    sort(b+2,b+n+1);
    for(int i=n;i>n-k+1;i--)
    	sum-=b[i];
    printf("%d\n",sum);
    return 0;
}