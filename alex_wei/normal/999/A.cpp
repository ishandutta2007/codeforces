#include<bits/stdc++.h>
using namespace std;
int n,k,p;
deque <int> j;
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>p,j.push_back(p);
	while(!j.empty()&&j.front()<=k)
		j.pop_front();
	while(!j.empty()&&j.back()<=k)
		j.pop_back();
	cout<<n-j.size();
	return 0;
}