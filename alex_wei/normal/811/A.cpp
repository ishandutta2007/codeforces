#include<bits/stdc++.h>
using namespace std;
int a,b,pd,c;
int main()
{
	cin>>a>>b;
	while(a>=0&&b>=0){
		c++;
		pd=!pd;
		pd?a-=c:b-=c;
	}
	if(a<0)cout<<"Vladik";
	else cout<<"Valera";
	return 0;
}