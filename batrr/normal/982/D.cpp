// Tima the best
#include <bits/stdc++.h>

#define ll long long                   
#define ld long double                
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=1e5+123,inf=1e8,mod=1e9+7,block=200,N=2053;
int n,a[maxn],b[maxn],pos[maxn], len[maxn] , ok[maxn], p[maxn], sz[maxn], cnt[maxn];
map<int,int>id;
vector<int> v;
set< pair<int,int> >st;
int getp(int v){
	if(p[v]==v)
		return v;
	return p[v]=getp(p[v]);
}
void Merge(int v,int u){
	int pv=getp(v);
	int pu=getp(u);
	if(pv==pu)    
		return;
	//cout<<u<<" "<<v<<endl;
	st.erase(mp(sz[pu],pu));
	st.erase(mp(sz[pv],pv));
	if( sz[pv] > sz[pu] ){       
		sz[pv]+=sz[pu];
		p[pu]=pv;
		st.insert(mp(sz[pv],pv));	
	}else{
		sz[pu]+=sz[pv];
		p[pv]=pu;
		st.insert(mp(sz[pu],pu));
	}
}
int main(){
	#ifdef LOCAL
    	freopen ("test.in", "r", stdin);
//	#else
//		freopen ("jumper.in", "r", stdin);
//		freopen ("jumper.out", "w", stdout);
	#endif               
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v.pb(a[i]);
	}     
	sort(v.begin(),v.end());
	for(int i=1;i<=n;i++)
		id[v[i-1]]=i;
	for(int i=1;i<=n;i++){
		b[i]=id[a[i]];
		pos[b[i]]=i;    

	}
		
	for(int k=1;k<=n;k++){
		sz[k]=1;
		p[k]=k;
		st.insert(mp(sz[k],p[k]));
		if(pos[k]!=1 && b[pos[k]-1]<k)
		    Merge(b[pos[k]-1],k);	
		if(pos[k]!=n && b[pos[k]+1]<k)
			Merge(b[pos[k]+1],k);	
		if( (*st.begin()).f==(*st.rbegin()).f )
			ok[k]=1,len[k]=(*st.begin()).f,cnt[k]=st.size();
    }
    int ans=1;
	for(int i=2;i<=n;i++){
		if( ok[i]  && cnt[i]>cnt[ans])
			ans=i;
	 //	cout<<i<<" "<<ok[i]<<" "<<cnt[i]<<" "<<len[i]<<endl;
	 }
	 cout<<v[ans-1]+1;

}