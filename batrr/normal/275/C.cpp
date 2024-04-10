#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <stack>
#include <cstdio>
#include <vector>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define iop(a) cout<<"Bag is here!!!"<<a<<endl
using namespace std;
const int maxn = 2e5 + 123; 
int n, k, b, ans, now;
set<ll>a;
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>b;	
		a.insert(b);
	}
	if(k==1){
		cout<<n;
		return 0;
	}
	for(set<long long >:: iterator i=a.begin();i!=a.end();i++){
		ll x = (*i) * k;
		a.erase(x);
	}
	cout<<a.size();;	
}