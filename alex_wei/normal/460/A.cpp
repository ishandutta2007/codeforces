#include<bits/stdc++.h>
using namespace std;
int m,n,c;
#define aba ababa
int main()
{
	cin>>n>>m;
	c++,n--;
	while(n||c%m==0){
		if(c%m==0)n++;
		n--,c++;
	}
	cout<<c;
	return 0;
}