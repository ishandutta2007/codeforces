#include<bits/stdc++.h>
using namespace std;
int s,pd,n,yue=1,ri=1,week=5,m[12]={31,29,31,30,31,30,31,31,30,31,30,31};
string p;
int main()
{
	cin>>n>>p>>p;
	if(p[0]=='w')pd=1;
	while(yue<13){
		if(pd==1&&week==n)s++;
		if(pd==0&&ri==n)s++;
		ri++,week++;
		if(ri>m[yue-1])ri=1,yue++;
		if(week>7)week=1;
	}
	cout<<s;
    return 0;
}