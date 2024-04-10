#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll x,a,b,n,pos;
vector <ll> oa,ob;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x>0)a+=x,oa.push_back(x);
		else b-=x,ob.push_back(-x),pos=i;
	}
	if(a>b)puts("first");
	else if(a<b)puts("second");
	else{
		int pd=0;
		for(int i=0;i<min(oa.size(),ob.size());i++)
			if(oa[i]<ob[i]){pd=1;break;}
			else if(oa[i]>ob[i]){pd=-1;break;}
		if(pd>0)puts("second");
		else if(pd<0)puts("first");
		else if(oa.size()<ob.size())puts("first");
		else if(oa.size()>ob.size())puts("second");
		else if(pos==n)puts("second");
		else puts("first");
	}
    return 0;
}