#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define me(x) memset(x,0,sizeof(x))
#define ll long long
using namespace std;
const int N=2e5;
int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout); 
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int h=1,t=n;
	while (h<t)
	{
		int mid=(h+t)/2,x1,x2;
		cout<<"? "<<mid<<endl;
		fflush(stdout);
		cin>>x1;
		cout<<"? "<<mid+1<<endl;
		fflush(stdout);
		cin>>x2;
		if (x1>x2) h=mid+1;
		else t=mid; 
	}
	cout<<"! "<<h<<endl; 
    return 0;
}