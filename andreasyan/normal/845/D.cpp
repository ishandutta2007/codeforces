#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int n,m;
int ans=0;
int main()
{
	scanf("%d",&m);
	int v;
	int a=0;
	stack<int> s;
	s.push(999);
	for(int ii=0;ii<m;++ii)
	{
		int k,x;
		scanf("%d",&k);
		if(k==1)
		{
			scanf("%d",&x);
			n=x;
			while(!s.empty())
			{
				if(n>s.top())
				{
					++ans;
					s.pop();
				}
				else
					break;
			}
		}
		if(k==2)
		{
			ans+=a;
			a=0;
		}
		if(k==3)
		{
			scanf("%d",&x);
			if(n>x)
			{
				++ans;
			}
			else
			{
				s.push(x);
			}
		}
		if(k==4)
		{
			a=0;
		}
		if(k==5)
		{
			s.push(999);
		}
		if(k==6)
		{
			++a;
		}
	}
	cout<<ans<<endl;
//	system("pause");
	return 0;
}