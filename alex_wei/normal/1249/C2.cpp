#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll q,n,t[100],s[100];
ll work(ll v)
{
//	cout<<v<<endl;
	if(v<=0)return 0;
	for(int i=0;i<50;i++)
		if(s[i]>=v)
			return t[i]+work(v-t[i]);
}
int main()
{
	cin>>q;
	t[0]=1,s[0]=1;
	for(int i=1;i<50;i++)
		if(t[i-1]<=1e18)
			t[i]=t[i-1]*3,s[i]=s[i-1]+t[i];
		else break;
	while(q--){
		cin>>n;
		int pos=0;
		cout<<work(n)<<endl;
	}
    return 0;
}