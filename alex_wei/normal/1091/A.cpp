#include<bits/stdc++.h>
using namespace std;
int y,b,r;
int main()
{
	cin>>y>>b>>r;
	cout<<min(y,min(b-1,r-2))*3+3;
    return 0;
}