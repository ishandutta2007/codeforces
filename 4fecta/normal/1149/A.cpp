#include <cstdio>
#include <iostream>
using namespace std;
int cnt[10];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++)
		scanf("%d",&x),cnt[x]++;
	if(cnt[1]*cnt[2]==0){
		int num;
		if(!cnt[1])num=2;
		else num=1;
		for(int i=1;i<=n;i++)
			printf("%d ",num);
		return 0;
	}
	--cnt[1],--cnt[2];
	printf("2 1 ");
	while(cnt[2]--)printf("2 ");
	while(cnt[1]--)printf("1 ");
	return 0;
}