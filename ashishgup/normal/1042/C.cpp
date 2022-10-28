#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, neg=0;
int a[N];
vector<int> zeroes;
vector<pair<int, int> > pos, negs;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
			zeroes.push_back(i);
		neg+=(a[i]<0);
		if(a[i]<0)
			negs.push_back({a[i], i});
		if(a[i]>0)
			pos.push_back({a[i], i});
	}	
	sort(negs.begin(), negs.end());
	for(int i=0;i+1<zeroes.size();i++)
		cout<<1<<" "<<zeroes[i]<<" "<<zeroes[i+1]<<endl;
	int to_delete=(zeroes.size()?zeroes.back():-1);
	if(neg%2)
	{
		int idx=negs.back().second;
		negs.pop_back();
		if(zeroes.size())
			cout<<1<<" "<<zeroes.back()<<" "<<idx<<endl;
		to_delete=idx;
	}
	if(!negs.size() && !pos.size())
		to_delete=-1;
	if(to_delete!=-1)
		cout<<2<<" "<<to_delete<<endl;
	for(int i=0;i+1<negs.size();i++)
		cout<<1<<" "<<negs[i].second<<" "<<negs[i+1].second<<endl;
	if(negs.size() && pos.size())
		cout<<1<<" "<<negs.back().second<<" "<<pos[0].second<<endl;
	for(int i=0;i+1<pos.size();i++)
		cout<<1<<" "<<pos[i].second<<" "<<pos[i+1].second<<endl;
	return 0;
}