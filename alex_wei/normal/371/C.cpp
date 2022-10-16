#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll nb,ns,nc,pb,ps,pc,r,x,y,z,now;
ll get(ll i){return pb*max((ll)0,i*x-nb)+ps*max((ll)0,i*y-ns)+pc*max((ll)0,i*z-nc);}
int main()
{
	cin>>s>>nb>>ns>>nc>>pb>>ps>>pc>>r;
	for(int i=0;i<s.size();i++){
		if(s[i]=='B')x++;
		if(s[i]=='S')y++;
		if(s[i]=='C')z++;
	}
	for(int i=1;;i++){
		ll cos=get(i);
		if(cos>r)cout<<i-1,exit(0);
		if((i*x>=nb||!x)&&(i*y>=ns||!y)&&(i*z>=nc||!z)){now=i;break;}
	}
	r-=get(now);
	cout<<now+r/(x*pb+y*ps+z*pc);
	return 0;
}