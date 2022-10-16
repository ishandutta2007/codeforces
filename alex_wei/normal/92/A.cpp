#include<bits/stdc++.h>
using namespace std;
int n,m,c=1; 
int main()
{
	cin>>n>>m;
	while(m-c>=0){
		m-=c;
		c++;
		if(c>n)c=1;
	}
	cout<<m;
    return 0;
}