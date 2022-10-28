#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int a, b, c, d;
char ans[N][N];

int32_t main()
{
    IOS;
    cin>>a>>b>>c>>d;
    cout<<"48 50\n";
    int pt=a-1;
    for(int i=0;i<12;i++)
    {
    	for(int j=0;j<50;j++)
    	{
    		if(i%2==0 && j%2==0 && pt>0)
    			cout<<"A", pt--;
    		else
    			cout<<"B";
    	}
    	cout<<endl;
    }
    pt=b-1;
    for(int i=0;i<12;i++)
    {
    	for(int j=0;j<50;j++)
    	{
    		if(i%2==1 && j%2==0 && pt>0)
    			cout<<"B", pt--;
    		else
    			cout<<"A";
    	}
    	cout<<endl;
    }
    pt=c-1;
    for(int i=0;i<12;i++)
    {
    	for(int j=0;j<50;j++)
    	{
    		if(i%2==0 && j%2==0 && pt>0)
    			cout<<"C", pt--;
    		else
    			cout<<"D";
    	}
    	cout<<endl;
    }
    pt=d-1;
    for(int i=0;i<12;i++)
    {
    	for(int j=0;j<50;j++)
    	{
    		if(i%2==1 && j%2==0 && pt>0)
    			cout<<"D", pt--;
    		else
    			cout<<"C";
    	}
    	cout<<endl;
    }
    return 0;
}