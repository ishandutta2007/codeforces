#include<bits/stdc++.h>
#define ll      long long
#define pb      push_back
#define mp      make_pair
#define orz     1000000007
using namespace std;
ll x,y,z;
int main(){
	cin>>x>>y>>z;
	x=(x-1)/z+1;
	y=(y-1)/z+1;
	cout<<x*y<<endl;
	return 0;
}