#include<bits/stdc++.h>
using namespace std;
int k; 
int main()
{
	cin>>k;
	for(int i=19;;i++){
		int r=i,c=0;
		while(r)c+=r%10,r/=10;
		if(c==10)k--;
		if(!k)cout<<i,exit(0);
	}
	return 0;
}