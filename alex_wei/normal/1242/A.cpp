#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,odd,eve;
bool isprime(ll x)
{
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)return false;
	return true;
}
int main()
{
	cin>>n;
	if(isprime(n))cout<<n;
	else{
		int cnt=0,p1;
		for(int i=2;i<=sqrt(n);i++)
			if(n%i==0){
				cnt++;
				p1=i;
				while(n%i==0)n/=i;
			}
		cnt+=n>1;
		if(cnt>1)cout<<1;
		else cout<<p1;
	}
    return 0;
}