#include<bits/stdc++.h>
using namespace std;
int t,a; 
int main()
{
	cin>>t;
	while(t--)cin>>a,cout<<(360%(180-a)?"NO\n":"YES\n");
	return 0;
}