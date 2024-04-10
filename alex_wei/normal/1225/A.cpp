#include<bits/stdc++.h>
using namespace std;
#define ll long long
int da,db; 
int main()
{
	cin>>da>>db;
	if(da==db)cout<<da<<"0 "<<db<<"1";
	else if(da==db-1)cout<<da<<"9 "<<db<<"0";
	else if(da==9&&db==1)cout<<"9 10";
	else cout<<-1;
    return 0;
}