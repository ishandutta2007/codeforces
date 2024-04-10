#include<bits/stdc++.h>
using namespace std;

#define db double
#define ll long long
#define ld long double
#define ull unsigned long long

#define pii pair <int,int>
#define fi first
#define se second
#define pb emplace_back
#define mem(x,v,s) memset(x,v,sizeof(x[0])*(s))
#define cpy(x,y,s) memcpy(x,y,sizeof(x[0])*(s))
/////////////////////////////////////
const int L=20;
const int N=1e5+5;
const int mod=1e9+7;

int n,q,size,val[N],pw[N],a[N];
bool canxor(int val){
	for(int i=19;~i;i--)if(val>>i&1)val^=a[i];
	return val==0;
}
void insert(int x){
	for(int i=19;~i;i--)
		if(x>>i&1){
			if(a[i]){x^=a[i]; continue;}
			for(int j=i-1;~j;j--)if(x>>j&1)x^=a[j];
			for(int j=i+1;j<20;j++)if(a[j]>>i&1)a[j]^=x;
			return a[i]=x,size++,void();
		}
}

int ans[N];
struct query{
	int l,x,id;
	bool operator < (const query &v) const{
		return l<v.l;
	}
}c[N];

int main(){
	cin>>n>>q,pw[0]=1;
	for(int i=1;i<=n;i++)pw[i]=(pw[i-1]<<1)%mod,cin>>val[i];
	for(int i=1;i<=q;i++)cin>>c[i].l>>c[i].x,c[i].id=i;
	sort(c+1,c+q+1);
	for(int i=1;i<=q;i++){
		for(int j=c[i-1].l+1;j<=c[i].l;j++)insert(val[j]);
		if(canxor(c[i].x))ans[c[i].id]=pw[c[i].l-size];
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<endl;
	return 0;
}