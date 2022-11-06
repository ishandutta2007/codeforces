//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
long long n,m,k,cnt;
int main()
{
	n=read(),m=read();
	if(m%n!=0)
	{
		puts("-1");return 0;
	}
	k=m/n;
	while(k%2==0)k=k/2,cnt++;
	while(k%3==0)k=k/3,cnt++;
	if(k==1)cout<<cnt<<endl;
	else puts("-1");
	return 0;
}
//cmll->zmf->zzm->dx->fyy->cmll