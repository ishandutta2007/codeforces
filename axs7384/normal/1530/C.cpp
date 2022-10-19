#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int t,a[N],n,b[N];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for (int i=1;i<=n;++i)
			scanf("%d",&b[i]);
		sort(a+1,a+1+n,greater<int>());
		sort(b+1,b+1+n,greater<int>());
		for (int i=1;i<=n;++i)
		{
			a[i]+=a[i-1];
			b[i]+=b[i-1];
		}
		for (int i=0;i<=n;++i)
		{
			int t=(i+n)-(i+n)/4;
			int A;
			int B;
			if (t<=i)
				A=100*t;
			else
				A=100*i+a[t-i];
			if (t<=n)
				B=b[t];
			else
				B=b[n];
			if (A>=B)
			{
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}