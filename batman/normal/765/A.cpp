#include <bits/stdc++.h>
using namespace std; 
#define ll long long
#define N ((ll)301*1000)

ll n;
string s,now;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	cout<<((n%2)?"contest":"home");
	return 0;
}