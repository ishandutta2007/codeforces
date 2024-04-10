#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define MOD ((ll)1e9+7)
#define INF ((ll)1e9)
#define N (301*1000)

string s;
ll h,m,n;

void add()
{
	m++;
	if(m==60)m=0,h++;
	if(h==24)h=0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s>>n;
	h=(s[0]-'0')*10+(s[1]-'0'),m=(s[3]-'0')*10+(s[4]-'0');
	while(n--)
		add();
	if(h<10)cout<<"0";
	cout<<h;
	cout<<":";
	if(m<10)cout<<"0";
	cout<<m;
	return 0;
}