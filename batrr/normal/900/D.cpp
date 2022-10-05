#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>

#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <stack>
#include <list>
#include <deque>

#include <ctime>
#include <cassert>
                                                        
#define ld long double
#define ll long long
#define f first
#define s second
#define pb push_back
#define p push
#define mp make_pair
#define o cout<<"BUG"<<endl;
using namespace std;
const int maxn=1e5,infi=1e9,mod=1e9+7;
const ll infl=1e18;
int x,y;
ll res[maxn];
vector<int > f;
ll binpow(int a,int n){
	if(n==0)
		return 1;
	ll c=binpow(a,n/2);
	if(n%2==0)
		return c*c%mod;
	return c*c%mod*a%mod;
}
int main(){                              //IO("")           	
	cin>>x>>y;
	if(y%x!=0){
		cout<<0;
		return 0;
	}
	y/=x;
	for(int i=1;i<=sqrt(y);i++){
		if(y%i==0){
			f.pb(i);
			if(i*i!=y)
				f.pb(y/i);
//			cout<<i<<" ";
		}
	}
	sort(f.begin(),f.end());
	reverse(f.begin(),f.end());
	for(int i=0;i<f.size();i++){
		res[i]=binpow(2,y/f[i]-1);
		for(int j=0;j<i;j++)
			if(f[j]%f[i]==0)
				res[i]=(res[i]-res[j]+mod)%mod;
//		cout<<res[i]<<" ";
	}
	cout<<res[f.size()-1];
}