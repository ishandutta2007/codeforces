#include<cstdio>
#include<algorithm>
using namespace std;
int N;
char buf[201010];
int a[27];
int minv[27];
int main()
{
	scanf("%d",&N);
	scanf("%s",buf);
	for(int i=0;i<N-1;i++)
	{
		a[buf[2*i]-'a']++;
		a[buf[2*i+1]-'A']--;
		minv[buf[2*i+1]-'A']=min(minv[buf[2*i+1]-'A'],a[buf[2*i+1]-'A']);
	}
	int ans=0;
	for(int i=0;i<26;i++)
		ans+=minv[i];
	printf("%d",-ans);
	return 0;
}