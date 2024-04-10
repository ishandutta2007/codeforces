#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=2e5;
int main()
{
	ios::sync_with_stdio(false);
    int T;
	cin>>T;
	while (T--)
	{   
	    int x,y;
	    cin>>x>>y;
	    if ((x+y)%2==0)
	    {
	    	x=x/2;
	    	y=(y+1)/2;
	    	cout<<x<<" "<<y<<endl; 
	    } else cout<<-1<<" "<<-1<<endl;
    }
	return 0; 
}