#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) \
	for(int i=(a),i##end=(b);i<i##end;i++)
#define mst(a,x) memset(a,x,sizeof(a))
struct SS{
	ll a,b;
	bool operator<(SS X)const{
		return a>X.a;
	}
}olds[7010],s[7010];
bool could[7010];
bool could2[7010];
ll n,nn;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	repeat(i,0,n)cin>>olds[i].a;
	repeat(i,0,n)cin>>olds[i].b;
	sort(olds,olds+n);
	nn=0;
	repeat(i,0,n){
		if(i==0 || olds[i].a!=olds[i-1].a){
			s[nn]=olds[i];
			could[nn]=false;
			could2[nn]=true;
			nn++;
		}
		else{
			could[nn-1]=true;
			s[nn-1].b+=olds[i].b;
		}
	}
	n=nn;
	//repeat(i,0,n)
		//cout<<s[i].a<<" -- "<<s[i].b<<' '<<could[i]<<endl;
	ll ans=0;
	repeat(I,0,n)
	if(could[I] && could2[I]){
		ans+=s[I].b;
		repeat(j,I+1,n)
		if(could2[j]){
			if(s[I].a==(s[I].a | s[j].a)){
				could2[j]=false;
				ans+=s[j].b;
			}
		}
		//ans=max(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}