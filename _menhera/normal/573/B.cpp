#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
int N;
int arr[101010];
multiset<int> minus_;
multiset<int> plus_;
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;++i) scanf("%d",arr+i);
	for(int i=0;i<=N+1;i++)
		minus_.insert(i+arr[i]);
	int maxv=0;
	for(int i=0;i<=N+1;i++)
	{
		//assert i+arr[i] is in minus
		minus_.erase(minus_.find(i+arr[i]));
		plus_.insert(-i+arr[i]);
		int ans=987654321;
		if(!minus_.empty()) ans=min(ans,*minus_.begin()-i);
		if(!plus_.empty()) ans=min(ans,*plus_.begin()+i);
		maxv=max(maxv,ans);
	}
	printf("%d",maxv);
}