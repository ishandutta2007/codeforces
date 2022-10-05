// Tima the best
#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 

#define ll long long                   
#define ld long double                
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=2e5+123,inf=1e8;

pair<ll,ll> p[maxn],h[maxn][26],base=mp(37,51),mod=mp(1e9+7,95542721);
int n,q,pre[maxn][26];
string s;
set<int>st[26];         
pair<ll,ll> get(int i, int j, int k){
    return mp( 
    (h[j][k].f-h[i-1][k].f*p[j-i+1].f%mod.f+mod.f)%mod.f,
    (h[j][k].s-h[i-1][k].s*p[j-i+1].s%mod.s+mod.s)%mod.s
    );
}
int cnt(int l, int r ,int k){
	return pre[r][k]-pre[l-1][k];
}
bool checkst(int x,int y, int len){
	int a=0,b=0;
	for(int i=0;i<26;i++){
		if( cnt(x,x+len-1,i)!=0 )
			a++;
		if( cnt(y,y+len-1,i)!=0 )
			b++;
	}
	return a==b;
}
int getf(int l,int i){
	if(st[i].lower_bound(l)!=st[i].end())
		return *st[i].lower_bound(l);
	else
		return 1e9;	
}
bool check(int x,int y,int len){
	if( checkst(x,y,len)==0 ){
//		cout<<"DSDF";
		return 0;
	}
	for(int i=0;i<26;i++){
		int id=getf(x,i);
		if(x+len-1<id)
			continue;
		int j=s[y+id-x]-'a';
		if( get(x,x+len-1,i)!=get(y,y+len-1,j) ){
		//	cout<<get(x,x+len-1,i).f<<endl;
		//	cout<<get(y,y+len-1,j).f<<endl;
		//	cout<<i<<" "<<id<<" "<<s[y+id-x];
			return 0;
		}
	}
	return 1;
}
int main(){
	#ifdef LOCAL
    	freopen ("test.in", "r", stdin);
	//#else
	//	freopen ("dictionary.in", "r", stdin);
	//	freopen ("dictionary.out", "w", stdout);
	#endif       
	cin>>n>>q;
	cin>>s;
	s='#'+s;
	p[0]=mp(1,1);
    for(int i=1;i<=n;i++){
        for(int j=0;j<26;j++){
       		if(j==s[i]-'a')                                                                     
       			h[i][j]=mp(h[i-1][j].f*base.f+1,h[i-1][j].s*base.s+1);
       		else
       			h[i][j]=mp(h[i-1][j].f*base.f,h[i-1][j].s*base.s);
        	h[i][j].f%=mod.f;
            h[i][j].s%=mod.s;
        }
        p[i]=mp(p[i-1].f*base.f%mod.f,p[i-1].s*base.s%mod.s);
    	st[s[i]-'a'].insert(i);
    }


    for(int i=1;i<=n;i++)
	    for(int j=0;j<26;j++)
    		pre[i][j]=pre[i-1][j]+(s[i]-'a'==j);
	
	while(q--){
		int x,y,len;
		cin>>x>>y>>len;
		if( check(x,y,len) )
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
}