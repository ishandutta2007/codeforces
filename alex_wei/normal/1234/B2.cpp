#include<bits/stdc++.h>
using namespace std;
//
#define ll long long
map <int,bool> mp;
int n,k,d[200005];
deque <int> c;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>d[i];
	for(int i=1;i<=n;i++){
		if(!mp[d[i]]){
			c.push_front(d[i]),mp[d[i]]=1;
			if(c.size()>k)mp[c[k]]=0,c.pop_back();
		}
	}
	cout<<c.size()<<endl;
	for(int i=0;i<c.size();i++)
		cout<<c[i]<<" ";
    return 0;
}