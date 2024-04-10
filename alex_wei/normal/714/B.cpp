#include<bits/stdc++.h>
using namespace std;
int n,a=-1,b=-1,c=-1,x;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		if(a==-1)a=x;
		else if(a!=x){
			if(b==-1)b=x;
			else if(b!=x){
				if(c==-1)c=x;
				else if(c!=x)cout<<"NO",exit(0);
			}
		}
	}
	if(c==-1)cout<<"YES",exit(0);
	if(a>b)swap(a,b);
	if(b>c)swap(b,c);
	if(a>b)swap(a,b);
	if(b-a==c-b)cout<<"YES";
	else cout<<"NO";
	return 0; 
}