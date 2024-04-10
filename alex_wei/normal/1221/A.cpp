#include<bits/stdc++.h>
using namespace std;
#define ll long long
int q,n,p[31],s[102]; 
int main()
{
	cin>>q;
	for(int i=1;i<=q;i++){
		memset(p,0,sizeof(p));
		cin>>n;
		for(int j=1;j<=n;j++)
			cin>>s[j],p[(int)log2(s[j])]++;
		for(int j=0;j<11;j++)
			p[j+1]+=p[j]/2,p[j]%=2;
		if(p[11])cout<<"YES\n";
		else cout<<"NO\n";
	}
    return 0;
}