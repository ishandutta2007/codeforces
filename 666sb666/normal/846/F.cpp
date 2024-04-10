#include<cstdio>
#include<map>
#include<vector>
using namespace std;
const int N=1e6+5;
int n,a[N];
long long cnt;
map<int,vector<int> > mp;
map<int,vector<int> >::iterator it;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),mp[a[i]].push_back(i);
	for(it=mp.begin();it!=mp.end();it++)
	{
		int lst=0;
		for(int i=0;i<(*it).second.size();i++)cnt+=(long long)((*it).second[i]-lst)*(n-(*it).second[i]+1),lst=(*it).second[i];
	}
	cnt=cnt*2-n;
	printf("%.10lf\n",(double)cnt/n/n);
	return 0;
}