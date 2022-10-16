#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k,d[205];
deque <int> c;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>d[i];
	for(int i=1;i<=n;i++){
		int pd=1;
		for(int j=0;j<c.size();j++)
			if(c[j]==d[i])
				pd=0;
		if(pd){
			c.push_front(d[i]);
			if(c.size()>k)c.pop_back();
		}
	}
	cout<<c.size()<<endl;
	for(int i=0;i<c.size();i++)
		cout<<c[i]<<" ";
    return 0;
}