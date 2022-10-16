#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll q,n,p[200005],s[200005],x,a,y,b,k;
bool cmp(ll a,ll b){return a>b;}
ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
int main()
{
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>n;
		for(int j=1;j<=n;j++)
			cin>>p[j],p[j]/=100;
		cin>>x>>a>>y>>b>>k;
		sort(p+1,p+n+1,cmp);
		for(int j=1;j<=n;j++)
			s[j]=s[j-1]+p[j];
		int pd=0;
		ll d=lcm(a,b);
		for(int j=1;j<=n;j++){
			ll aa=j/a,bb=j/b;
			if(!aa&&!bb)continue;
			ll dd=j/d;
			ll cal1=(s[aa]-s[0])*x+(s[dd]-s[0])*y+(s[aa+bb-dd]-s[aa])*y,
			   cal2=(s[bb]-s[0])*y+(s[dd]-s[0])*x+(s[aa+bb-dd]-s[bb])*x;
			if(cal1>=k||cal2>=k){
				pd=1;
				cout<<j<<endl;
				break;
			}
		}
		if(!pd)cout<<"-1\n";
	}
    return 0;
}