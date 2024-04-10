#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

#define M 300200

using namespace std;

int n,a[M];

void read(void){
	scanf("%d",&n);
	for (int i=1; i<=n; ++i)
	scanf("%d",a+i);
	sort(a+1,a+(n+1));
}

void kill(void){
	long long s=0;
	for (int i=1; i<=n; ++i)
	s=s+abs(a[i]-i);
	printf("%I64d\n",s);
}

int main()
{
	ios_base::sync_with_stdio(false);
	read();
	kill();
	return 0;
}