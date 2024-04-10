#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (110)
#define INF ((ll)1e11)
#define MOD ((ll)1e9+7)

ll vp,vd,t,f,c,ans;
ld p;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>vp>>vd>>t>>f>>c;
	if(vp>=vd)return cout<<0,0;
	p=t*vp;
	while(p<c)
	{
		ll ex=vd-vp;
		p+=(ld)p/ex*vp;
		if(p>=c)break;
		ans++;
		p+=((ld)p/vd+f)*vp;
	}
	cout<<ans;
    return 0;
}