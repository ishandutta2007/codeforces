#include <iostream>
#include <vector>
#include <algorithm>

#define long long long
#define f first
#define s second
#define mp make_pair

using namespace std;

long a1,a2,n,k,s=0,ans=0,ans1;
vector< pair< long, pair<long,long> > > h;

void read(void){
	cin>>n;
	for (int i=0,x,y,m; i<n; ++i){
		cin>>k;
		s+=k;
		cin>>a1;
		long t=a1;
		cin>>x>>y>>m;
		h.push_back(mp(0,mp(a1,i+1)));
		ans1=0;
		for (int j=1; j<k; ++j){
			a2=(a1*x+y)%m;
			if (a2<a1)
			ans1++;
			a1=a2;
			t=max(t,a1);
			if (h.size()<=200000)
			h.push_back(mp(ans1,mp(a1,i+1)));
		}
		ans=max(ans,ans1);
	}
	
	sort(h.begin(),h.end());
	
	cout<<ans<<"\n";
	
	if (s<=200000)
	for (int i=0; i<s; ++i)
	cout<<h[i].s.f<<" "<<h[i].s.s<<"\n";
	
}


int main()
{
	ios_base::sync_with_stdio(false);
	read();
	return 0;
}