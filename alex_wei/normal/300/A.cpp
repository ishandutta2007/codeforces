#include<bits/stdc++.h>
using namespace std;
int n,a;
vector <int> ne,z,po;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a==0)z.push_back(a);
		if(a<0)ne.push_back(a);
		if(a>0)po.push_back(a);
	}
	cout<<1<<" "<<ne.back()<<endl;
	ne.pop_back();
	if(po.size()==0){
		cout<<2<<" "<<ne.back();
		ne.pop_back();
		cout<<" "<<ne.back()<<endl;
		ne.pop_back();
	}
	else{
		cout<<1<<" "<<po.back()<<endl;
		po.pop_back();
	}
	cout<<ne.size()+po.size()+z.size()<<" ";
	for(int i=0;i<ne.size();i++)
		cout<<ne[i]<<" ";
	for(int i=0;i<z.size();i++)
		cout<<0<<" ";
	for(int i=0;i<po.size();i++)
		cout<<po[i]<<" ";
	return 0;
}