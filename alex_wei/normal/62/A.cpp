#include<bits/stdc++.h>
using namespace std;
int a1,a2,b1,b2;
int main()
{
	cin>>a1>>a2>>b1>>b2;
	if(a1-1<=b2&&a1*2+2>=b2||a2-1<=b1&&a2*2+2>=b1)cout<<"YES";
	else cout<<"NO";
	return 0;
}