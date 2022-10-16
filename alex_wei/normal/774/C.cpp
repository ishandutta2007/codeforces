#include <bits/stdc++.h>
using namespace std;
int n; 
int main()
{
	cin>>n;
	if(n%2){
		cout<<7;
		for(int i=3;i<n;i+=2)
			cout<<1;
	}
	else{
		for(int i=0;i<n;i+=2)
			cout<<1;
	}
    return 0;
}