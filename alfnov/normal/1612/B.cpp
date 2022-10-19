#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,a,b;
		cin>>n>>a>>b;
		queue<int>q1,q2;
		int nn=n>>1;
		q1.push(a),q2.push(b);
		for(int i=1;i<a;i++)if(i!=b)q2.push(i);
		for(int i=b+1;i<=n;i++)if(i!=a)q1.push(i);
		for(int i=a+1;i<b;i++)
		{
			if(q1.size()<nn)q1.push(i);
			else q2.push(i);
		}
		if(q1.size()>nn||q2.size()>nn)printf("-1\n");
		else
		{
			while(q1.size())
			{
				int x=q1.front();
				q1.pop();
				printf("%d ",x);
			}
			while(q2.size())
			{
				int x=q2.front();
				q2.pop();
				printf("%d ",x);
			}
			printf("\n");
		}
	}
	return 0;
}