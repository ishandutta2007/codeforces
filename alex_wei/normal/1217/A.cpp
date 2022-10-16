#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,str,in,ex; 
int get(int l,int r)
{
	if(l==r)return l;
	int m=l+r>>1;
	if(str+m>in+ex-m)return get(l,m);
	else return get(m+1,r);
}
int main()
{
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>str>>in>>ex;
		int p=get(0,ex+1);
		cout<<ex-p+1<<endl;
	}
    return 0;
}