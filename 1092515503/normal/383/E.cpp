#include<bits/stdc++.h>
using namespace std;
const int lim=(1<<24);
int n,f[1<<24],res;
char s[5];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%s",s),f[(1<<(s[0]-'a'))|(1<<(s[1]-'a'))|(1<<(s[2]-'a'))]++;
	for(int j=0;j<24;j++)for(int i=1;i<lim;i++)if(i&(1<<j))f[i]+=f[i^(1<<j)];
	for(int i=0;i<lim;i++)res^=(n-f[i])*(n-f[i]);
	printf("%d\n",res);
	return 0;
}