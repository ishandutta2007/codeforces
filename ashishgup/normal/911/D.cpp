#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1505;

int n;
int a[N], bit[N], b[N][N], c[N][N];

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    }
    int inv=0;
    for(int i=2;i<=n;i++)
    {
    	for(int j=1;j<i;j++)
    	{
    		if(a[j]>a[i])
    			inv++;
    	}
    }
    inv%=2;
    int m;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
    	int l, r;
    	cin>>l>>r;
    	int num=r-l+1;
    	int maxinv=num*(num-1)/2;
    	inv+=maxinv;
    	inv%=2;
    	if(inv)
    		cout<<"odd"<<endl;
    	else
    		cout<<"even"<<endl;
    }
    return 0;
}