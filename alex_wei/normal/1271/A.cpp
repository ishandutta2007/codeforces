#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b,c,d,e,f;
int main(){
	cin>>a>>b>>c>>d>>e>>f;
	if(e>f)printf("%lld",e*min(a,d)+f*min(min(d-min(a,d),b),c));
	else printf("%lld",f*min(min(d,b),c)+e*min(a,d-min(min(d,b),c)));
    return 0;
}