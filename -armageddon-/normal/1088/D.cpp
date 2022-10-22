#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cinng(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfng(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
char big;
int pa,pb; 

void query(int a,int b)
{
	cout<<"? "<<a<<' '<<b<<endl;
	fflush(stdout);
}

int main()
{
//	freopen("input.txt","r",stdin);
	query(0,0);
	int st;
	cin>>st;
	if(st==1) big='a';
	if(st==-1) big='b';
	if(st==0) big='d';
	for(int i=29;i>=0;i--)
	{
		int x,y;
		query(pa|(1<<i),pb);
		cin>>x;
		query(pa,pb|(1<<i));
		cin>>y;
		if(big=='d')
		{
			if(x==-1)
			{
				pa|=(1<<i);
				pb|=(1<<i);
			}
		}
		else if(big=='a')
		{
			if(x==-1)
			{
				pa|=(1<<i);
				if(y==-1)
				{
					big='b';
				}
				if(y==0)//impossible
				{
					big='d';
				}
				if(y==1)
				{
					pb|=(1<<i);
					big='a';
				}
			}
			else if(x==0)
			{
				pa|=(1<<i);
				big='d';
			}
			else if(x==1)
			{
				if(y==1)
				{
					pa|=(1<<i);
					big='a';
				}
				else if(y==0)//impossible
				{
					
				}
				else if(y==-1)
				{
					big='a';
				}
			}
		}
		else if(big=='b')
		{
//			swap(x,y);
			x=-x;
			y=-y;
			if(y==-1)
			{
				pb|=(1<<i);
				if(x==-1)
				{
					big='a';
				}
				if(x==0)//impossible
				{
					big='d';
				}
				if(x==1)
				{
//					cout<<"S";
					pa|=(1<<i);
					big='b';
				}
			}
			if(y==0)
			{
				pb|=(1<<i);
				big='d';
			}
			if(y==1)
			{
				if(x==1)
				{
					pb|=(1<<i);
					big='b';
				}
				else if(x==0)//impossible
				{
					
				}
				else if(x==-1)
				{
					big='b';
				}
			}
		}
	}
	cout<<"! "<<pa<<' '<<pb<<endl;
	fflush(stdout);
	return 0;
}