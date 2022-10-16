#include<bits/stdc++.h>
using namespace std;
int n,m,c,mm,cc;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>c;
		if(m>c)mm++;
		if(c>m)cc++;
	}
	if(mm>cc)cout<<"Mishka";
	else if(mm<cc)cout<<"Chris";
	else cout<<"Friendship is magic!^^";
	return 0;
}