#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	cin>>n>>m;
	if(log2(m)>=n)cout<<m%(1<<n);
	else cout<<m;
    return 0;
}