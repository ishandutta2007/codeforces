#include <bits/stdc++.h>
using namespace std;
int n; 
int main()
{
	cin>>n;
	if(n%3)cout<<"1 "<<n%3<<" "<<n-n%3-1;
	else cout<<"1 1 "<<n-2;
    return 0;
}