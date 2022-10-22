#include <bits/stdc++.h>
#define mp make_pair
#define ll long long 
#define pii pair<int,int>
#define all(A) A.begin(),A.end()
const int inf=1018181818;
using namespace std;
int n;
int a[200005];
vector <int> vec[1000005];
vector <int> res;

void push(int x)
{
	for(int i=0;i<vec[x].size();i++)
	{
		res.push_back(vec[x][i]);
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		vec[a[i]].push_back(i+1);
	}
	sort(a,a+n);
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
	}
//	cout<<sum<<endl;
	if(sum-a[n-1]-a[n-2]==a[n-2]) push(a[n-1]);
	n=unique(a,a+n)-a;
	for(int i=0;i<n-1;i++)
	{
//		cout<<sum-a[n-1]-a[i]<<endl;
		if(sum-a[n-1]-a[i]==1LL*a[n-1]) push(a[i]);
	}
	cout<<res.size()<<endl;
	for(int i=0;i<res.size();i++)
	{
		printf("%d ",res[i]);
	}
	return 0;
}