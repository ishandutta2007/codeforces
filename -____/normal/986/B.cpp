//CF 986B
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
const int N = 1e6+16;
int n,a[N],b[N];
int main()
{
	int i,j,s;
	scanf("%d",&n);
	s=n;
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	for(i=1;i<=n;i=i+1){
		if(!b[i]){
			s--;
			j=i;
			do{
				b[j]=1;
				j=a[j];
			}while(j!=i);
		}
	}
	if((n^s)&1)
		cout<<"Um_nik";
	else
		cout<<"Petr";
	return 0;
}