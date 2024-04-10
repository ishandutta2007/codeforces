#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int a[10101],b[10101],f[10101];
map<int,bool> M;
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=k;i++)
		cin>>b[i];
	int ans=0,cnt=0,N=0;
	for(int i=1;i<=n;i++)
	{
		cnt+=a[i];
		M.clear();
		int tmp=b[1]-cnt;
		bool flag=0;
		for(int i=1;i<=n;i++)
		{
			tmp+=a[i];
			M[tmp]=1;
		}
		for(int i=1;i<=k;i++)
		if(M[b[i]]==0)
		{
			flag=1;
			break;
		}
		if(flag==0)
		{
			N++;
			f[N]=cnt;
		}
	}
	f[0]=-12376125;
	sort(f+1,f+N+1);
	for(int i=1;i<=N;i++)
	if(f[i]!=f[i-1])
		ans++;
	cout<<ans<<endl;
	return 0;
}