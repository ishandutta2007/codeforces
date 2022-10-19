#include<bits/stdc++.h>
#define LL long long
using namespace std;
int len,Test_num;
int to[202];
char sl[18],sr[18],ch[18];
LL f[18][2][2];
inline LL calc(char s[])
{
	LL res=0;
	len=strlen(s+1);
	for(int d=0;d<16 && d<(len<<2);++d)
	{
		memset(f,0,sizeof(f)),f[len][0][1]=1;
		for(int i=len;i;--i)
			for(int j=0;j<2;++j)
				for(int k=0;k<=d;++k)
				{
					if((d>>2)==i-1 && !((k>>(d&3))&1))continue;
					f[i-1][j|(k==d)][0]+=f[i][j][0];
					if(k<=to[s[i]])f[i-1][j|(k==d)][k==to[s[i]]]+=f[i][j][1];
				}
		res+=f[0][1][0]+f[0][1][1];
	}
	return res;
}
int main()
{
	for(int i='0';i<='9';++i)ch[to[i]=(i^48)]=i;
	for(int i='a';i<='f';++i)ch[to[i]=i-'a'+10]=i;
	for(scanf("%d",&Test_num);Test_num--;)
	{
		scanf("%s%s",sl+1,sr+1),len=strlen(sr+1);
		for(int i=1;i<len+1-i;++i)swap(sr[i],sr[len+1-i]);
		len=strlen(sl+1);
		for(int i=1;i<len+1-i;++i)swap(sl[i],sl[len+1-i]);
		for(int i=1;;++i)
		{
			if(to[sl[i]] || i==len)
			{
				sl[i]=ch[to[sl[i]]-1];
				if(i==len && sl[i]=='0')sl[i]=0;
				break;
			}
			sl[i]=ch[15];
		}
		printf("%lld\n",calc(sr)-calc(sl));
	}
	return 0;
}