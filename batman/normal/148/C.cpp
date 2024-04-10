#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (1010)
#define INF ((ll)1e15)
#define MOD ((ll)1e9+7)

ll n,a,b;
vector <ll> ans;

int main()
{
	cin>>n>>a>>b;
	if(!b && a && n<a+2)return cout<<-1,0;
	ans.push_back(1);
	if(!b && a)ans.push_back(1),n--;
	for(ll i=0,sum=1;i<b;i++)
		ans.push_back(sum+1),sum+=sum+1;
	for(int i=0;i<a;i++)
		ans.push_back(ans[ans.size()-1]+1);
	for(int i=0;i<n-a-b-1;i++)
		ans.push_back(1);
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";			
    return 0;
}