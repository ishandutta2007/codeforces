#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,t,x,a,b; 
int main()
{
	cin>>t;
	while(t--){
		cin>>n>>x>>a>>b;
		if(a>b)swap(a,b);
		int up=min(n-b,x);
		b+=up,x-=up;
		int down=min(a-1,x);
		a-=down;
		cout<<b-a<<endl;
	}
    return 0;
}