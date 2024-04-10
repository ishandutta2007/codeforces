#include<bits/stdc++.h>
using namespace std;
int t,n;
const int N=100005;
int a[N];
int q[N],cnt;
int main()
{
	cin>>t;
	while (t--)
	{
		cin>>n;
		for (int i=1;i<=n;++i)
			if (!a[i])
			{
				if (i==n)
				{
					a[n]=n;
					for (int j=1;j<n;++j)
						a[n]^=j^a[j];
					break;
				}
				cout<<"? "<<i<<endl;
				fflush(stdout);
				cin>>q[cnt=1];
				while (true)
				{
					cout<<"? "<<i<<endl;
					fflush(stdout);
					cin>>q[++cnt];
					a[q[cnt-1]]=q[cnt];
					if (q[cnt]==q[1])
					{
						--cnt;
						break;
					}
				}
				/*int pos=0;
				for (int j=1;j<=cnt;++j)
					if (q[j]==i)
					{
						pos=j;
						break;
					}
				int tot=0;
				for (int j=pos;j<=cnt;++j)
					p[++tot]=q[j];
				for (int j=1;j<=pos;++j)*/
			}
		cout<<'!';
		for (int i=1;i<=n;++i)
		{
			cout<<' '<<a[i];
			a[i]=0;
		}
		cout<<endl;
		fflush(stdout);
	}
	return 0;
}