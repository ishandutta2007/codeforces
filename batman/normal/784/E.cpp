#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)301*1000)

bool a,b,c,d;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>a>>b>>c>>d;
	cout<<(((a^b)&(c|d))^((b&c)|(a^d)));
	return 0;
}