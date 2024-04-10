#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,n1,Test_num;
double ans;
vector<LL> v1,v2;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),n1=(n<<1),v1.clear(),v2.clear(),ans=0;
		for(int i=1,x,y;i<=n1;++i)
		{
			read(x),read(y);
			if(!x)v1.push_back(abs(y));
			else v2.push_back(abs(x));
		}
		sort(v1.begin(),v1.end()),sort(v2.begin(),v2.end());
		for(int i=0;i<n;++i)ans+=sqrt(v1[i]*v1[i]+v2[i]*v2[i]);
		printf("%.15lf\n",ans);
	}
	return 0;
}