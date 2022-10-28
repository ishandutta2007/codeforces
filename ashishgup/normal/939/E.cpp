#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5e5+5;

int ind=0;
long double a[N], pref[N];

long double ans(int k)
{
	long double finans=a[ind];
	long double subtract=(a[ind]+pref[k])/(k+1);
	finans-=subtract;
	return finans;
}

int ternary_search(int lo, int hi)
{
	while(lo<hi-2)
	{
		int m1=(lo*2+hi)/3;
		int m2=(lo+2*hi)/3;
		if(ans(m1)>ans(m2))
			hi=m2;
		else
			lo=m1;
	}
	int index=lo;
	for(int i=lo;i<=hi;i++)
	{
		if(ans(i)>ans(index))
			index=i;
	}
	return index;
}

int32_t main()
{
    IOS;
    int q;
    cin>>q;
    while(q--)
    {
    	int type;
    	cin>>type;
    	if(type==1)
    	{
    		int x;
    		cin>>x;
    		ind++;
    		a[ind]=x;
    		pref[ind]=pref[ind-1]+x;
    	}
    	else
    	{
    		int index=ternary_search(1, ind);
    		cout<<fixed<<setprecision(12)<<ans(index)<<endl;
    	}
    }
    return 0;
}