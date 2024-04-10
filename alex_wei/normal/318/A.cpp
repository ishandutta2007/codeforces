#include<bits/stdc++.h>
using namespace std;
long long n,k; 
int main()
{
	cin>>n>>k;
	if(k>(n%2?n/2+1:n/2))cout<<(k-n/2-(n%2?1:0))*2;
	else cout<<k*2-1;
    return 0;
}