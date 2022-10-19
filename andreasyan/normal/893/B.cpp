#pragma comment(linker,"/STACK:2000000")
#define _CRT_SECURE_NO_WARNINGS
#define mp make_pair
#define OLYMP
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <cstring>
void fp();
void sp();
using namespace std;

int n;
bool stg(int x)
{
	for(int k=0;k<32;++k)
	{
		if(((1<<k)-1)*(1<<(k-1))==x)
			return true;
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	int ans;
	for(int i=1;i<=n;++i)
	{
		if(n%i==0)
		{
			if(stg(i))
				ans=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}

void fp()
{
#ifndef OLYMP
	freopen("","r",stdin);
	freopen("","w",stdout);
#endif
}
void sp()
{
#ifdef OLYMP
	system("pause");
#endif
}