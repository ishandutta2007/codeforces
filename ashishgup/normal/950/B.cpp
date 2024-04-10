#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m;
int x[N], y[N];

int32_t main()
{
    IOS;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    	cin>>x[i];
    for(int i=1;i<=m;i++)
    	cin>>y[i];
    int left=1, right=1, val1=0, val2=0, ans=0;
    do
    {
    	val1+=x[left++];
   		while(val1!=val2)
   		{
   			if(x[left]+val1<=y[right]+val2 && left<=n)
	    	{
	    		val1+=x[left++];
	    	}
	    	else
	    	{
	    		val2+=y[right++];
	    	}
   		}
   		ans++;
    }while(left<=n || right<=m);
    cout<<ans;
    return 0;
}