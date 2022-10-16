#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll q,num,mut=1;
int main()
{
	cin>>q;
	if(q==1)num=1;
	for(int i=2;i<=sqrt(q);i++)
		while(q%i==0){
			num++;
			if(num<3)mut*=i;
			q/=i;
		}
	if(q>1)num++;
	if(num==1)cout<<"1\n0";
	if(num==2)cout<<2;
	if(num>2)cout<<"1\n"<<mut;
	return 0;
}