#include<bits/stdc++.h>
using namespace std;
int x,y,pd;
int main()
{
	cin>>x>>y;
	while(x*10+y>21&&y>1){
		if(!pd){
			if(x>1)x-=2,y-=2;
			else if(x)x--,y-=12;
			else y-=22;
		}
		else{
			if(y>21)y-=22;
			else if(y>11)x--,y-=12;
			else x-=2,y-=2;
		}
		pd=!pd;
	}
	if(pd)cout<<"Ciel";
	else cout<<"Hanako"; 
	return 0;
}