//CF1491A
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 111111;
int n,q,k,a[N];
int main()
{
	int i,x;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		k+=a[i];
	}
	while(q--){
		scanf("%d%d",&i,&x);
		if(i==1){
			if(a[x])
				k--;
			else
				k++;
			a[x]^=1;
		}
		else{
			if(x<=k)
				printf("1\n");
			else
				printf("0\n");
		}
	}
	return 0;
}