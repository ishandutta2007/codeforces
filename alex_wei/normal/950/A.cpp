#include <bits/stdc++.h>
using namespace std;
int l,r,a,s;
int main()
{
	cin>>l>>r>>a;
	if(l<r){
		int n=r-l;
		if(a<=n)s=l+a;
		else s=r+(a-n)/2;
	}
	else{
		int n=l-r;
		if(a<=n)s=r+a;
		else s=l+(a-n)/2;
	}
	cout<<s*2;
    return 0;
}