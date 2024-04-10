#include <bits/stdc++.h>
using namespace std;
int x; 
int main()
{
	cin>>x;
	if(x==3)cout<<5,exit(0);
	for(int i=0;i<=100;i++)
		if(((i*2+1)*(i*2+1)+1)/2>=x)
			cout<<2*i+1,exit(0);
    return 0;
}