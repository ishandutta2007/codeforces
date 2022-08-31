//CF 920C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
int n,a[222222];
char ch[222222];
int main()
{
	int i,p;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	scanf("%s",ch+1);
	p=1;
	for(i=1;i<=n;i=i+1){
		if(ch[i]!='1'){
			sort(a+p,a+i+1);
			p=i+1;
		}
	}
	for(i=1;i<n;i=i+1)
		if(a[i]>a[i+1]){
			cout<<"NO";
			return 0;
		}
	cout<<"YES";
	return 0;
}