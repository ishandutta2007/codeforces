#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int arr[101010];
int appear[1010101];
int mina[1010101];
int maxa[1010101];
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",arr+i);
	memset(mina,0x3f,sizeof(mina));
	for(int i=0;i<N;i++)
	{
		appear[arr[i]]++;
		mina[arr[i]]=min(mina[arr[i]],i);
		maxa[arr[i]]=max(maxa[arr[i]],i);
	}
	pair<int,int> maxv=make_pair(0,0x3f3f3f3f);
	int l=0,r=0;
	for(int i=0;i<1010100;i++)
	{
		if(maxv<make_pair(appear[i],mina[i]-maxa[i]))
		{
			maxv=make_pair(appear[i],mina[i]-maxa[i]);
			l=mina[i];
			r=maxa[i];
		}
	}
	printf("%d %d",l+1,r+1);
	return 0;
}