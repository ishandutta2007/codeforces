#include<bits/stdc++.h>
using namespace std;
int a1,a2,b1,b2,l; 
int main()
{
	cin>>a1>>b1>>a2>>b2,l=max(abs(a1-a2),abs(b1-b2));
	if(a1==a2)cout<<a1+l<<" "<<b1<<" "<<a2+l<<" "<<b2;
	else if(b1==b2)cout<<a1<<" "<<b1+l<<" "<<a2<<" "<<b2+l;
	else if(abs(a1-a2)!=abs(b1-b2))cout<<-1;
	else cout<<a1<<" "<<b2<<" "<<a2<<" "<<b1;
	return 0;
}