#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,Test_num,l,r,mid,Mid,I,J,K;
LL tot,tmp,tmp1,t;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool check(LL x)
{
	LL y=sqrt(x*2);
	return y*(y+1)==x*2;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),l=1,r=n,printf("? %d %d\n",l,r),fflush(stdout),read(tot);
		//if(tot==-1)return 0;
		while(l<=r)
		{
			mid=((l+r)>>1),printf("? %d %d\n",l,mid),fflush(stdout),read(tmp);
			//if(tmp==-1)return 0;
			if(!tmp)
			{
				l=mid;
				continue;
			}
			if(tmp==tot)
			{
				r=mid+1;
				continue;
			}
			if(check(tmp))
			{
				t=sqrt(tmp*2),printf("? %lld %d\n",mid-t,mid),fflush(stdout),read(tmp1);
				//if(tmp1==-1/* && Test_num && mid==3 && t==1*/)return 0;
				if(tmp==tmp1)
				{
					I=mid-t,J=mid;
					for(l=mid+1;l<=r;)
					{
						Mid=((l+r)>>1),printf("? %d %d\n",I,Mid),fflush(stdout),read(tmp1);
						//if(tmp1==-1/* && !Test_num*/)return 0;
						if(tmp1==1LL*(Mid-I+1)*(Mid-I)/2)J=Mid,l=Mid+1;
						else r=Mid-1;
					}
					tot-=1LL*(J-I+1)*(J-I)/2,t=sqrt(tot*2),K=J+1+t,++J;break;
				}
			}
			//if(!check(tot-tmp))return 0;
			printf("? %d %d\n",mid+1,r),fflush(stdout),read(tmp),t=sqrt(tmp*2),K=mid+1+t,J=mid+1;
			//if(mid<=n && K>n)return 0;
			for(r=mid;l<=r;)
			{
				Mid=((l+r)>>1),printf("? %d %d\n",Mid,K),fflush(stdout),read(tmp1);
				//if(tmp1==-1 && K>n)return 0;
				if(tmp1==1LL*(K-Mid+1)*(K-Mid)/2)J=Mid,r=Mid-1;
				else l=Mid+1;
			}
			tot-=1LL*(K-J+1)*(K-J)/2,t=sqrt(tot*2),I=J-1-t;break;
		}
		printf("! %d %d %d\n",I,J,K),fflush(stdout);
	}
	return 0;
}
/*
1000000000 1 3 1000000000
499999997500000004

124999998750000004


2
5
? 1 5
4
? 1 3
1
? 2 5
3
? 3 5
3
! 1 3 5
5
? 1 5
5
? 1 3
1
? 2 6
*/