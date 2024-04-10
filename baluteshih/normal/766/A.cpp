#include <iostream>
using namespace std;

int max(int a,int b)
{
	if(a>b) return a;
	return b;
}

int main()
{
	string a,b;
	cin >> a >> b;
	if(a.size()!=b.size()) cout << max(a.size(),b.size());
	else if(a!=b) cout << a.size();
	else cout << -1;
	cout << "\n";
}