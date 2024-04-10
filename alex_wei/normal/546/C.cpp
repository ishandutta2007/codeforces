#include<bits/stdc++.h>
using namespace std;
int n,k1,k2;
deque <int> a,b;
int main()
{
	cin>>n>>k1;
	for(int i=1;i<=k1;i++)cin>>k2,a.push_back(k2);
	cin>>k2;
	for(int i=1;i<=k2;i++)cin>>k1,b.push_back(k1);
	for(int i=0;i<100000;i++){
		if(!a.size())cout<<i<<" 2",exit(0);
		if(!b.size())cout<<i<<" 1",exit(0);
		int p=a.front(),q=b.front();
		a.pop_front(),b.pop_front();
		if(p>q)a.push_back(q),a.push_back(p);
		if(p<q)b.push_back(p),b.push_back(q);
	}
	cout<<-1;
	return 0;
}