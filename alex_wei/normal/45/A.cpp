#include<bits/stdc++.h>
using namespace std;
map <string,int> s;
string f,t[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
int k;
int main()
{
	s["January"]=0,s["February"]=1,s["March"]=2,s["April"]=3,s["May"]=4,s["June"]=5,s["July"]=6,s["August"]=7,s["September"]=8,s["October"]=9,s["November"]=10,s["December"]=11;
	cin>>f>>k;
	cout<<t[(s[f]+k)%12];
	return 0;
}