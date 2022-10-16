#include<bits/stdc++.h>
using namespace std;
int n,k,cnt,r;
int main()
{
	cin>>n>>k,r=n;
	for(int i=2;i<=sqrt(n);i++)
		while(r%i==0)cnt++,r/=i;
	if(r>1)cnt++;
	r=n;
	if(cnt<k)cout<<-1;
	else{
		for(int i=2;i<=sqrt(n);i++)
			while(k>1&&r%i==0)cout<<i<<" ",r/=i,k--;
		cout<<r;
	}
    return 0;
}