#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)201*1000)
#define INF ((ll)1e9+10)
#define MOD ((ll)1e9+7)
ll tavan(ll a,ll b,ll mod=MOD){ll res=1;while(b){res*=b%2?a:1;res%=mod;a*=a;a%=mod;b/=2;}return res;}

ll n;
string s;
bool flg=0;
ll ans1,ans2,now;

bool let(char c)
{
	return ('a'<=c && c<='z') || ('A'<=c && c<='Z');
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		if(!let(s[i]))ans1=max(ans1,now),now=0;
		if(!flg && let(s[i]))now++;
		if(flg)
		{
			if(let(s[i]) && (i==0 || !let(s[i-1])))ans2++;
		}
		if(s[i]=='('){flg=1;continue;}
		if(s[i]==')'){flg=0;continue;}	
	}
	ans1=max(ans1,now);
	cout<<ans1<<" "<<ans2<<"\n";
	return 0;
}