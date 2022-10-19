#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
int len,n,res,vec_t=0,f_t=0,S,t1,t2,la,ta,lb,tb,ans;
int to[531441]={},l[68282],to1[68282];
int f[452][68282];
char s[50002],a[5],b[5];
vector<int> vec[68282];
inline void init()
{
	scanf("%s%d",s,&n),len=strlen(s),S=sqrt(4*len);
	for(int i=0;i<len;++i)
	{
		res=0;
		for(int j=0;j<4 && i+j<len;++j)
		{
			res=res*26+s[i+j]-'a'+1;
			if(!to[res])l[to[res]=(++vec_t)]=j;
			vec[to[res]].push_back(i);
		}
	}
	for(int i=1;i<=vec_t;++i)
		if(vec[i].size()>=S)
		{
			to1[i]=(++f_t),t1=0;
			for(int j=1;j<=vec_t;++j)f[f_t][j]=len;
			for(int j=0;j<len;++j)
			{
				while(t1+1<vec[i].size() && vec[i][t1+1]<=j)++t1;
				res=0;
				for(int k=0;k<4 && j+k<len;++k)
				{
					res=res*26+s[j+k]-'a'+1,f[f_t][to[res]]=min(f[f_t][to[res]],max(vec[i][t1]+l[i],j+k)-min(vec[i][t1],j)+1);
					if(t1+1<vec[i].size())f[f_t][to[res]]=min(f[f_t][to[res]],max(vec[i][t1+1]+l[i],j+k)-min(vec[i][t1+1],j)+1);
				}
			}
		}
}
int main()
{
	for(init();n--;)
	{
		scanf("%s%s",a,b),la=strlen(a),lb=strlen(b),ta=tb=0;
		for(int i=0;i<la;++i)ta=ta*26+a[i]-'a'+1;
		for(int i=0;i<lb;++i)tb=tb*26+b[i]-'a'+1;
		if(!(ta=to[ta]) || !(tb=to[tb]))puts("-1");
		else if(vec[ta].size()>=S)printf("%d\n",f[to1[ta]][tb]);
		else if(vec[tb].size()>=S)printf("%d\n",f[to1[tb]][ta]);
		else
		{
			t1=t2=0,ans=len;
			while(t1<vec[ta].size() && t2<vec[tb].size())
			{
				ans=min(ans,max(vec[ta][t1]+l[ta],vec[tb][t2]+l[tb])-min(vec[ta][t1],vec[tb][t2])+1);
				if(vec[ta][t1]+l[ta]>vec[tb][t2]+l[tb])++t2;else ++t1;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}