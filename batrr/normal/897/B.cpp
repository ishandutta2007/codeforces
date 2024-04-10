#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <cstdio> 
#include <deque>
#include <map>
#include <iomanip>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ull unsigned long long
#define ll long long
#define GG(a) cout<<"Bug is here!!!"<<a<<endl
using namespace std;
const int m=1e9+7,maxn=1e6+123;                                
int n,a[maxn],q,w;
vector<ll>ans;
void rec(vector<ll> a){
	if(a.size()>=6)
		return;
	ll g=0;
	for(int i=0;i<a.size();i++)
		g=g*10+a[i];
	for(int i=0;i<a.size();i++)
		g=g*10+a[a.size()-1-i];
	//cout<<g<<endl;
	ans.pb(g);
	a.pb(1);
	for(int i=0;i<10;i++){
		a[a.size()-1]=i;
		rec(a);
	}
}                    
int main(){                               
	for(int i=1;i<10;i++){
		vector<ll>a;
		a.pb(i);
		rec(a);	
	}
	sort(ans.begin(),ans.end());  
	ll k,g,sum=0;
	ans.pb((ans[ans.size()-1]+1)*10+1);
	cin>>k>>g;
	for(int i=0;i<k;i++){
		sum=(sum+ans[i]%g)%g;
	}
	cout<<sum;
	return 0;
}