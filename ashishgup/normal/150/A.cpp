#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int q;
	cin>>q;
	map<int, int> m;
	for(int i=2;i*i<=q;i++)
	{
		int ct=0;
		while(q%i==0)
		{
			q/=i;
			ct++;
		}
		if(ct>0)
			m[i]=ct;
	}	
	if(q>1)
		m[q]=1;
	if(!m.size())
	{
		cout<<"1"<<endl;
		cout<<"0";
		return 0;
	}
	if(m.size()==1)
	{
		int k=m.begin()->second;
		if(k==1)
		{
			cout<<"1"<<endl;
			cout<<"0";
		}
		else if(k==2)
		{
			cout<<"2";
		}
		else
		{
			cout<<"1"<<endl;
			cout<<m.begin()->first*m.begin()->first;
		}
		return 0;
	}
	int ct1=0;
	for(auto it:m)
		ct1+=(it.second==1);
	if(m.size()==2 && ct1==2)
	{
		cout<<"2";
		return 0;
	}
	cout<<"1"<<endl;
	cout<<m.begin()->first * ((++m.begin())->first);
	return 0;
}