#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
vector <int> k;
int main()
{
	cin>>a>>b;
	d=b;
	while(b>a){
		c++;
		k.push_back(b);
		if(b%10==1)b/=10;
		else if(b%2==0)b/=2;
		else cout<<"NO",exit(0);
	}
	if(b!=a)cout<<"NO",exit(0);
	cout<<"YES\n"<<k.size()+1<<endl<<a<<" ";
	for(int i=k.size()-1;i>=0;i--)
		cout<<k[i]<<" ";
	return 0;
}