#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL a[3],b[3];
inline void copy()
{
	for(int i=0;i<3;++i)b[i]=a[i];
	sort(b,b+3);
}
inline bool query(LL x)
{
	int y;
	printf("%lld\n",x),fflush(stdout),scanf("%d",&y);
	if(!y)return 1;
	return a[y-1]+=x,0;
}
int main()
{
	for(int i=0;i<3;++i)scanf("%lld",&a[i]);
	puts("First"),fflush(stdout);
	if(copy(),query(2*b[2]-b[1]-b[0]))return 0;
	if(copy(),query(2*b[2]-b[1]-b[0]))return 0;
	return copy(),query(b[1]-b[0]),0;
}