#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,r,g,b; 
int main()
{
	cin>>t;
	while(t--){
		cin>>r>>g>>b;
		if(r<g)swap(r,g);
		if(g<b)swap(g,b);
		if(r<g)swap(r,g);
		int k=g-b;
		r-=k,g-=k;
		cout<<k+min(g+b,(r+g+b)/2)<<endl;
	}
    return 0;
}