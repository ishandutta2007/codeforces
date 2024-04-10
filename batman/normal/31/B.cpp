#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define MOD ((ll)1e9+7)
#define INF ((ll)1e9)
#define N (301*1000)

string s,ex;
vector <string> ans;
bool mark;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	if(s[(ll)s.size()-1]=='@')return cout<<"No solution",0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='@' && ((ll)ex.size()==0 || mark))return cout<<"No solution",0;
		ex+=s[i];
		if(mark)ans.push_back(ex),mark=0,ex="";
		if(s[i]=='@')mark=1;
	}
	if((ll)ans.size()==0)return cout<<"No solution",0;
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i];
		if(i!=(ll)ans.size()-1)cout<<',';
	}
	cout<<ex;
	return 0;
}