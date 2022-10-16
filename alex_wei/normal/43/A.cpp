#include<bits/stdc++.h>
using namespace std;
int n,f,s;
string a,b,c;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c;
		if(!f||a==c)a=c,f++;
		else b=c,s++;
	}
	if(f>s)cout<<a;
	else cout<<b;
    return 0;
}