#include<cstdio>
int main()
{
	int N;
	long long int M;
	scanf("%d%I64d",&N,&M);
	int a[88];
	int l=0,r=N-1;
	int binary[88];
	M--;
	for(int i=N-2;i>=0;i--)
	{
		binary[i]=M%2;
		M/=2;
	}
	for(int i=0;i<N;i++)
	{
		if(binary[i]==1) a[r--]=i+1;
		else a[l++]=i+1;
	}
	for(int i=0;i<N;i++) printf("%d ",a[i]);
}