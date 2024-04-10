#include<bits/stdc++.h>
using namespace std;
const int N=1<<18;
int n,lim,sa[N],m,buc[N],x[N],y[N];
char s[N];
int main(){
	scanf("%d%s",&n,s),lim=1<<n,m=26;
	for(int i=0;i<lim;i++)buc[x[i]=s[i]-'a']++;
	for(int i=1;i<m;i++)buc[i]+=buc[i-1];
	for(int i=lim-1;i>=0;i--)sa[--buc[x[i]]]=i;
	for(int k=1;k<lim;k<<=1){
		int num=0;
		for(int i=0;i<lim;i++)y[num++]=sa[i]^k;
		for(int i=0;i<m;i++)buc[i]=0;
		for(int i=0;i<lim;i++)buc[x[y[i]]]++;
		for(int i=1;i<m;i++)buc[i]+=buc[i-1];
		for(int i=lim-1;i>=0;i--)sa[--buc[x[y[i]]]]=y[i],y[i]=0;
		swap(x,y),x[sa[0]]=num=0;
		auto mat=[&](int i,int j){return y[i]==y[j]&&y[i^k]==y[j^k];};
		for(int i=1;i<lim;i++)x[sa[i]]=(mat(sa[i],sa[i-1])?num:++num);
		m=num+1;
		if(m==lim)break;
	}
	for(int i=0;i<lim;i++)putchar(s[sa[0]^i]);
	return 0;
}