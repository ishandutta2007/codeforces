#include <bits/stdc++.h>
using namespace std;
int check(int n)
{
	while(n){
		if(n%10!=4&&n%10!=7)
			return 0;
		n/=10;
	}
	return 1;
}
int n;
int main()
{
	cin>>n;
	if(!(n%4)||!(n%7))cout<<"YES",exit(0);
	for(int i=1;i<=n;i++)
		if(n%i==0&&check(i))
			cout<<"YES",exit(0);
	cout<<"NO";
    return 0;
}