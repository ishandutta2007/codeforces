#include<bits/stdc++.h>
using namespace std;
#define ll long long
int l,r; 
int main()
{
	cin>>l>>r;
	for(int i=l;i<=r;i++){
		int tmp=i,p=1;
		int pd[10];
		memset(pd,0,sizeof(pd));
		while(tmp){
			if(pd[tmp%10])p=0;
			pd[tmp%10]=1;
			tmp/=10;
		}
		if(p)cout<<i,exit(0);
	}
	cout<<-1;
    return 0;
}