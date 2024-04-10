#include<bits/stdc++.h>
using namespace std;
long long cnt,a,b; 
int main()
{
	cin>>a>>b;
	while(a&&b){
		if(b>a)swap(a,b);
		cnt+=a/b;
		a%=b;
	}
	cout<<cnt;
	return 0;
}