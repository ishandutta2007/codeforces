#include <bits/stdc++.h>
 
#define nm "A" 
#define stdi freopen(nm".in","r",stdin);
#define stdo freopen(nm".out","w",stdout);
#define IO stdi stdo                   
#define ll long long                                                                                                            
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=3e5+123,N=2e6+123,mod=1e9+7,block=600;
ll n,x;
vector< pair < ll , ll > >ans;
map < ll , set<int> > m;
int main(){ 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		m[x].insert(i);
	}
	for(map< ll , set < int > > :: iterator it=m.begin();it!=m.end();it++){
		x=(*it).f;
		while(m[x].size()>=2){
			m[x].erase(m[x].begin());
			m[x+x].insert(*m[x].begin());
			m[x].erase(m[x].begin());
    	}
    	if(m[x].size()==1)
    		ans.pb(mp(*m[x].begin(),x));	
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<ans[i].s<<" ";
}