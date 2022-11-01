#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (301*1000)
#define INF ((ll)1e16)
#define MOD ((ll)1e9+7)

ll n,sum;
bool mark;
deque <ll> num[3];
vector <ll> ans;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		ll a;
		cin>>a;
		sum+=a;
		if(a==0)mark=1;
		if(a%3==0)ans.push_back(a);
		else num[a%3].push_back(a);
	}
	if(!mark)return cout<<-1,0;
	sort(num[1].begin(),num[1].end());sort(num[2].begin(),num[2].end());
	if(sum%3==1 && (ll)num[1].size()>0)num[1].pop_front();
	else if(sum%3==1)num[2].pop_front(),num[2].pop_front();
	if(sum%3==2 && (ll)num[2].size()>0)num[2].pop_front();
	else if(sum%3==2)num[1].pop_front(),num[1].pop_front();
    for(int i=0;i<num[1].size();i++)ans.push_back(num[1][i]);
    for(int i=0;i<num[2].size();i++)ans.push_back(num[2][i]);
    sort(ans.begin(),ans.end());
	if(ans[(ll)ans.size()-1]==0)return cout<<0,0;
	for(int i=(ll)ans.size()-1;i>=0;i--)cout<<ans[i];
    return 0;
}