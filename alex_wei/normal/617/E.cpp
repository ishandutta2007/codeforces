#include <bits/stdc++.h> /////////////////////////
using namespace std;

#define db double
#define ll long long
#define ld long double
#define ull unsigned long long
#define vint vector <int>
#define vpii vector <pii>

#define pii pair <int,int>
#define fi first
#define se second
#define pb emplace_back
#define mem(x,v,s) memset(x,v,sizeof(x[0])*(s))
#define cpy(x,y,s) memcpy(x,y,sizeof(x[0])*(s))

const int N=1e5+5;
const int B=333;

int n,m,k,a[N],buc[N<<4];
struct query{
	int l,r,b,id;
	bool operator < (const query &v) const {
		return b!=v.b?b<v.b:b&1?r>v.r:r<v.r; 
	}
}q[N];
ll cur,ans[N];
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)cin>>a[i],a[i]^=a[i-1];
	for(int i=1;i<=m;i++){
		cin>>q[i].l>>q[i].r,q[i].l--;
		q[i].b=q[i].l/B,q[i].id=i;
	}
	sort(q+1,q+m+1),buc[0]=1;
	for(int i=1,l=0,r=0;i<=m;i++){
		while(r<q[i].r)r++,cur+=buc[a[r]^k],buc[a[r]]++;
		while(l>q[i].l)l--,cur+=buc[a[l]^k],buc[a[l]]++;
		while(r>q[i].r)buc[a[r]]--,cur-=buc[a[r]^k],r--;
		while(l<q[i].l)buc[a[l]]--,cur-=buc[a[l]^k],l++;
		ans[q[i].id]=cur;
	}
	for(int i=1;i<=m;i++)printf("%lld\n",ans[i]);
	return 0;
}