#include <bits/stdc++.h>
using namespace std;
long long s,n; 
int main()
{
	cin>>n,n++;
	if(n%2==0||n==1)cout<<n/2;
	else cout<<n;
    return 0;
}