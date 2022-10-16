#include<bits/stdc++.h>
using namespace std;
int a,b;
int jc(int x){return x==1?1:jc(x-1)*x;} 
int main()
{
	cin>>a>>b;
	cout<<jc(min(a,b));
	return 0;
}