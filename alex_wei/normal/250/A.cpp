#include<bits/stdc++.h>
using namespace std;
int n,c,f,a;
queue <int> p;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a<0)f++;
		if(f>2)f=1,p.push(c),c=0;
		c++;
	}
	p.push(c);
	cout<<p.size()<<endl;
	while(!p.empty())cout<<p.front()<<" ",p.pop();
	return 0;
}