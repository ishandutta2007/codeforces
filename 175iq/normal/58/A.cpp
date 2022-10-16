#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <map>
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int> 
#define PDD pair<double,double>
#define LL long long
 
using namespace std;
 
char msk[200];
string hello="hello";
int len,x,y;
 
int main()
{
	scanf("%s",msk);len=strlen(msk);
	x=0,y=-1;
	do
	{
		y++;
		if(hello[x]==msk[y]) x++;
	}while((x<5)&&(y+1<len));
	printf("%s\n",x==5?"YES":"NO");
	return 0;
}