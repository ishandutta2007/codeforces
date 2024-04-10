#pragma GCC optimize("O3","unroll-loops")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define F first
#define S second
#define MP make_pair
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll arr[100005];

int main()
{jizz
    ll n,sum=0;
    string a="sjfnb",b="cslnb";
    cin >> n;
    for(int i=0;i<n;++i)
    	cin >> arr[i];
    sort(arr,arr+n);
    for(int i=0;i+1<n;++i)
    	if(arr[i]==arr[i+1])
    	{
    		if(arr[i]==0)
    			return cout << b << "\n",0;
    		--arr[i],swap(a,b);
    		break;
		}
	for(int i=0;i+1<n;++i)
    	if(arr[i]==arr[i+1])
    		return cout << a << "\n",0;
    	else sum+=(arr[i+1]-arr[i]-1)*(n-i-1);
   	sum+=arr[0]*n;
    if(sum&1) cout << a << "\n";
    else cout << b << "\n";
}