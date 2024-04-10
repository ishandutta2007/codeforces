#include<bits/stdc++.h>
using namespace std;
long long A[1005],AA[1005];
int a[1005],b[1005],c[1005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		A[i]=AA[i]=1000000ll*b[i]+i;
	}
	sort(AA+1,AA+n+1);
	for(int i=1;i<=n;i++)a[i]=lower_bound(AA+1,AA+n+1,A[i])-AA;
	for(int i=1;i<=n;i++)c[a[i]]=i;
	int cnt=0;
	for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)
		if(b[i]>b[j])cnt++;
	cout<<cnt<<endl;
	set<int>se;
	for(int i=1;i<n;i++)if(c[i]>c[i+1])se.insert(i);
	while(se.size())
	{
		int x=*(se.begin());
		int A=c[x],B=c[x+1];
		if(A>B)swap(A,B);
		if(a[A]!=a[B])printf("%d %d\n",A,B),swap(a[A],a[B]);
		swap(c[x],c[x+1]);
		if(x-1>=1)se.erase(x-1);
		se.erase(x);
		if(x+1<n)se.erase(x+1);
		if(x-1>=1&&c[x-1]>c[x])se.insert(x-1);
		if(c[x]>c[x+1])se.insert(x);
		if(x+1<n&&c[x+1]>c[x+2])se.insert(x+1);
	}
	return 0;
}