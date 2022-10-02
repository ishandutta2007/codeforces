#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005],b[1000005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,k;
		cin >> n >> k;
		if(n==4&&k==3)
		{
			cout << "-1\n";
			continue;
		}
		if(n==4&&k==2)
		{
			cout << "0 1\n2 3\n";
			continue;
		}
		if(n==8&&k==7)
		{
			cout << "0 1\n7 6\n3 5\n2 4\n";
			continue;
		}
		if(n==8&&k==5)
		{
			cout << "1 7\n4 6\n2 5\n3 0\n";
			continue;
		}
		for(int i=0;i<n/2;i++)
			a[i]=i,b[i]=n-i-1;
		int flag=0;
		for(int i=1;i<n/2;i++)
		{
			int x=k-(i^1);
			if(x<n/2&&(x!=1&&x!=i||i==1))
			{
				swap(a[0],a[x]),swap(a[1],a[i]);
				int sum=0;
				for(int i=0;i<n/2;i++)
					sum+=a[i]&b[i];
		//		cerr << sum << "*\n";
				for(int i=0;i<n/2;i++)
					cout << a[i] << " " << b[i] << "\n";
				flag=1;
				break;
			}
		}
		if(!flag&&n>4)
		{
			swap(a[2],a[3]),--k;
			for(int i=3;i<n/2;i++)
			{
				int x=k-(i^1);
				if(x>=3&&x<n/2&&(x!=1&&x!=i||i==1))
				{
					swap(a[0],a[x]),swap(a[1],a[i]);
					int sum=0;
					for(int i=0;i<n/2;i++)
						sum+=a[i]&b[i];
			//		cerr << sum << "*\n";
					for(int i=0;i<n/2;i++)
						cout << a[i] << " " << b[i] << "\n";
					flag=1;
					break;
				}
			}
		}
	}
	return 0;
}