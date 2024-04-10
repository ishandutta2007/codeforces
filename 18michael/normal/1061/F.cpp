#include<bits/stdc++.h>
using namespace std;
int n,k,d=0,res=0,res1=1;
char s[3];
vector<int> vec;
bool u[1502]={};
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	srand(time(NULL)),read(n),read(k);
	while(res<n)res+=res1,res1*=k,++d;
	for(int x,y;;)
	{
		vec.clear();
		do x=rand()%n+1,y=rand()%n+1;while(x==y);
		for(int i=1;i<=n;++i)
			if(i!=x && i!=y)
			{
				printf("? %d %d %d\n",x,i,y),fflush(stdout),scanf("%s",s);
				if(s[0]=='Y')vec.push_back(i);
			}
		if(vec.size()<2*d-3)continue;
		for(int i=0;i<vec.size();++i)
		{
			res=0;
			for(int j=0;j<vec.size();++j)if(j!=i)printf("? %d %d %d\n",x,vec[j],vec[i]),fflush(stdout),scanf("%s",s),res+=(s[0]=='Y');
			if(res==d-2)
			{
				printf("! %d\n",vec[i]),fflush(stdout);
				break;
			}
		}
		break;
	}
	return 0;
}