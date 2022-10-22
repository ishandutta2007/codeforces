#include <bits/stdc++.h>
#define rep(i,h,t) for (int i=h;i<=t;i++)
using namespace std;
const int N=3e5;
char s[N];
int a[N];
int main()
{
	int n;
	cin>>n;
	rep(i,1,n)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int k1=abs(c-a),k2=abs(d-b);
		if (k1>0&&k2>0) cout<<k1+k2+2<<endl;
		else cout<<k1+k2<<endl;
    }
	return 0; 
}