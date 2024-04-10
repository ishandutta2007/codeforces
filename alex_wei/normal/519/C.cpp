#include<bits/stdc++.h>
using namespace std;
int n,m,s;
int main()
{
	cin>>n>>m;
	while(n>=1&&m>=2||n>=2&&m>=1){
		if(n>=m)
			n-=2,m--,s++;
		else
			n--,m-=2,s++;
	}
	cout<<s;
	return 0;
}