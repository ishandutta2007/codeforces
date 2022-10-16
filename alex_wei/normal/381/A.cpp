#include<bits/stdc++.h>
using namespace std;
int n,a,b,k;
deque <int> c; 
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>k,c.push_back(k);
	for(int i=0;i<n;i++){
		int len=c.size()-1,pls=0;
		if(c[len]>c[0])pls=c[len],c.pop_back();
		else pls=c[0],c.pop_front();
		i%2?b+=pls:a+=pls;
	}
	cout<<a<<" "<<b<<endl;
	return 0;
}