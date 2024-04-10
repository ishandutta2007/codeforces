#include<bits/stdc++.h>
using namespace std;
int x,h,m,s;
int main()
{
	cin>>x>>h>>m;
	while(h%10!=7&&m%10!=7){
		s++,m-=x;
		if(m<0)m+=60,h--;
		if(h<0)h=23;
	}
	cout<<s;
	return 0;
}