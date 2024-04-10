#include<bits/stdc++.h>
using namespace std;
int n,a;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a)cout<<"HARD",exit(0);
	}
	cout<<"EASY";
	return 0;
}