#include<cstdio>
const int MAXN = 202020;
int arr[MAXN];
int arr2[MAXN];
int brr[MAXN];
int brr2[MAXN];
int N;
void rearr(int arr[], int brr[])
{
	int k =0 ;
	for(int i=0; i<N; i++)
		if(arr[i] == 1)
			k=i;
	int tp=0;
	for(int i=k; i<N; i++)
		if(arr[i])
			brr[tp++]=arr[i];
	for(int i=0; i<k; i++)
		if(arr[i])
			brr[tp++]=arr[i];
}
int main()
{
	scanf("%d",&N);
	for(int i=0; i<N; i++) scanf("%d",arr+i);
	for(int i=0; i<N; i++) scanf("%d",arr2+i);
	rearr(arr,brr);
	rearr(arr2,brr2);
	for(int i=0; i<N-1;i++)
		if(brr[i]!=brr2[i])
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}