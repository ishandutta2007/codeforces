// Tima the best
#include <bits/stdc++.h>
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
*/
#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=2e5+123,inf=1e18,mod=1e9+7,N=2e5+12;
string s;
int pre[maxn],good[maxn],ans;
int t[4*maxn],add[4*maxn];
int get(int len){
	int res=0;
	for(int i=1;i+len-1<s.size();i++){
		int l=i,r=i+len-1,a=pre[r]-pre[l-1],b=len-a;
        if(  a <= 2*b )
			//cout<<l<<" "<<r<<" "<<a<<" "<<b<<endl;
			res++;
	}
	return res;
}

void up(int v,int tl,int tr,int l,int r,int val){
	if(l>r)
		return;
	if(tl==l && tr==r){
		t[v]+=val;
		add[v]+=val;
		return;
	}
	int tm=(tl+tr)/2;             
	up(v+v,tl,tm,l,min(tm,r),val);
	up(v+v+1,tm+1,tr,max(tm+1,l),r,val);
	t[v]=max(t[v+v],t[v+v+1])+add[v];
}
int get(int v,int tl, int tr, int l, int r){
	if(l>r)
		return -1e7;
	if(tl==l && tr==r)
		return t[v];
	int tm=(tl+tr)/2;
	return max(get(v+v,tl,tm,l,min(tm,r)),get(v+v+1,tm+1,tr,max(tm+1,l),r))+add[v];	
}
int main(){
    #ifdef LOCAL
		freopen ("test.in", "r", stdin);
    #endif     
	cin>>s;                                             
	good['a']=good['e']=good['i']=good['o']=good['u']=1;
	good['A']=good['E']=good['I']=good['O']=good['U']=1;
	s="#"+s;
    for(int i=1;i<s.size();i++){
    	pre[i]=pre[i-1]+good[s[i]];
		
		up(1,1,N,i,i,pre[i-1]*3);
		up(1,1,N,1,i,2);
		/*        
		cnta<=cntb *2
		cnta<=len*2-cnta*2
		3cnta<=2len
		3pre[r]<=2*len+3pre[l-1]
		0000111111111
		*/
		/*
		cout<<i<<endl;
		for(int i=1;i<s.size();i++)
			cout<<get(1,1,N,i,i)<<" ";cout<<endl;
		*/
		if( 3*pre[i] <= get(1,1,N,1,i) ){
			int l=0,r=i;
			while(l<=r){
				int m=(l+r)/2;
				if( 3*pre[i] <= get(1,1,N,1,m) )
					r=m-1;
				else
					l=m+1;
			}
			ans=max(ans,i-l+1);
		}                    
	}	
	if(ans==0)
		cout<<"No solution";
	else
		cout<<ans<<" "<<get(ans)<<endl;
}