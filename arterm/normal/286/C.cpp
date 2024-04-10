#include <iostream>
#include <stack>
#include <cstdlib>

#define M 1001000

using namespace std;

int n,a[M],m;
stack<int> s;

void read(void){
	cin>>n;
	for (int i=0; i<n; ++i)
	cin>>a[i];
	cin>>m;
	for (int i=0,x; i<m; ++i)
	cin>>x,a[x-1]*=-1;
}

void kill(void){
	for (int i=n-1; i>=0; --i)
	if (s.size()==0 || s.top()!=a[i])
	s.push(abs(a[i])),a[i]=-s.top();
	else
	s.pop();
	if (s.size()>0){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	for (int i=0; i<n; ++i,cout<<" ")
	cout<<a[i];
}

int main()
{
	ios_base::sync_with_stdio(0);
	read();
	kill();
	return 0;
}