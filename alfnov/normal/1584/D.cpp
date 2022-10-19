#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T=1;
	cin>>T;
	while(T--)
	{
		int n,len;
		cin>>n;
		cout<<"? "<<1<<" "<<n<<endl;
		long long aa;
		cin>>aa;
		len=n;
		for(int i=(1<<30);i>=1;i>>=1)if(len>=i)
		{
			cout<<"? "<<len-i+1<<" "<<n<<endl;
			long long bb;
			cin>>bb;
			if(aa!=bb)len-=i;
		}
		cout<<"? "<<len+1<<" "<<n<<endl;
		long long cc;
		cin>>cc;
		int el=len+(aa-cc)+1;
		int a=aa-cc+1;
		long long x=aa-1ll*a*(a-1)/2;
		int le=(sqrt(1.5+8*x)+1)/2,k=el-1+le;
		cout<<"! "<<len<<" "<<el<<" "<<k<<endl;
	}
	return 0;
}