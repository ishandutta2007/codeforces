#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++) 
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
int T;
char c[1000];
int main()
{
    cin>>T;
    rep(i,1,T)
    {
    	int n;
    	cin>>n;
    	cin>>c;
    	for (int j=0;j<=2*n-2;j+=2) cout<<c[j];
    	cout<<endl;
    }
	return 0; 
}