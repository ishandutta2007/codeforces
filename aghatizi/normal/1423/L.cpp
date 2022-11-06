#include<bits/stdc++.h>

using namespace :: std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second

const int  maxn=1100;
const ll inf=1e9+900;


bitset<maxn> bi[maxn];

vector<pair<bitset<maxn> , int> > vec1;
unordered_map<bitset<maxn> , int> ml;
bitset<maxn> dp[1<<21];

void build(vector<pair<bitset<maxn> , int> > &vec,int l,int r,bool justadd=0){
	int t=r-l;
	for(int i=0;i<(1<<t);i++){
		if(i!=0)dp[i]=dp[i^(i&(-i))]^bi[__builtin_ctz(i)+l];
		if(justadd){
			if(ml.count(dp[i])==0){
				ml[dp[i]]=__builtin_popcount(i);
			}else{
				ml[dp[i]]=min(ml[dp[i]],__builtin_popcount(i));
			}
		}else{
			vec.pb(mp(dp[i],__builtin_popcount(i)));
		}
	}
}

int main(){
	int n,s,d;
	cin>>n>>s>>d;
	for(int i=0;i<s;i++){
		int c;
		cin>>c;
		while(c--){
			int v;
			cin>>v;
			bi[i][v]=1;
		}
	}
	int p=min(s/2,9);
	build(vec1,0,p);
	build(vec1,p,s,1);
	while(d--){
		int t;
		cin>>t;
		bitset<maxn> a=0;
		while(t--){
			int v;
			cin>>v;
			a[v]=1;
		}
		int ans=inf;
		for(auto v:vec1){
			if(ml.count(v.F^a)){
				ans=min(ans,v.S+ml[v.F^a]);
			}
		}
		if(ans==inf){
			cout<<-1<<endl;
		}else{
			cout<<ans<<endl;
		}
	}

}