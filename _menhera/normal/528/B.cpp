#include<cstdio>
#include<algorithm>
using namespace std;
int N;
pair<int,int> seg[200200];
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		seg[i].second=a-b;
		seg[i].first=a+b;
	}
	int mfil=-1987654321;
	sort(seg,seg+N); // end, start
	int cnt=0;
	for(int i=0;i<N;i++)
	{
		if(mfil<=seg[i].second)
		{
			mfil=seg[i].first;
			cnt++;
		}
	}
	printf("%d",cnt);
}