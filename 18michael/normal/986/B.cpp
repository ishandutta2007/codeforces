#include<bits/stdc++.h>
using namespace std;
int n,res;
int a[1000002],to[1000002];
int main()
{
	scanf("%d",&n),res=(n&1);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),to[a[i]]=i;
	for(int i=1;i<=n;++i)if(a[i]!=i)res^=1,swap(a[i],a[to[i]]),swap(to[a[i]],to[a[to[i]]]);
	return 0&puts(res? "Um_nik":"Petr");
}