#include<bits/stdc++.h>
using namespace std;
int h1,a1,c,h2,a2,s,r1,r2; 
int main()
{
	cin>>h1>>a1>>c>>h2>>a2,r1=h1,r2=h2;
	while(h2>0){
		s++;
		if(h2<=a1)break;
		else if(h1<=a2)h1+=c-a2;
		else h1-=a2,h2-=a1;
	}
	cout<<s<<endl;
	while(r2>0){
		if(r2<=a1){cout<<"STRIKE";break;}
		else if(r1<=a2)r1+=c-a2,cout<<"HEAL\n";
		else r1-=a2,r2-=a1,cout<<"STRIKE\n";
	}
    return 0;
}