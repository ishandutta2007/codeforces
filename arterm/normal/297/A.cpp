#include <iostream>
#include <string>

using namespace std;

string a, b;

int one(string s){
	int n=s.length(),a=0;
	for (int i=0; i<n; ++i)
	if (s[i]=='1')
	a++;
	return a;
}

int main()
{
	cin>>a>>b;
	int x=one(a),y=one(b);
	if (x%2==1)
	x++;
	if (x>=y){
		cout<<"YES\n";
		return 0;
	}
	cout<<"NO\n";
	return 0;
}