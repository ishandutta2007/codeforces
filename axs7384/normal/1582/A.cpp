#include<bits/stdc++.h>
using namespace std;
int t,x,y,z;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%d",&x,&y,&z);
		cout<<(x%2+z%2)%2<<endl;
	}
	return 0;
}