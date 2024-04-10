#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int dx[2]={-1, +1};

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
    	int n, k, d1, d2;
    	cin>>n>>k>>d1>>d2;
    	int have=n-k;
    	int check=0;
    	for(int i=0;i<2;i++)
    	{
    		for(int j=0;j<2;j++)
    		{
    			int a=0;
    			int b=dx[i]*d1;
    			int c=b+dx[j]*d2;
    			int reqd=3*max({a, b, c}) - a - b - c;
    			int played=a + b + c - 3*min({a, b, c});
    			if(have>=reqd && (have-reqd)%3==0 && k>=played && (k-played)%3==0)
    			{
    				check=1;
    			}
     		}
    	}
    	if(check)
    		cout<<"yes"<<endl;
    	else
    		cout<<"no"<<endl;
    }
	return 0;
}