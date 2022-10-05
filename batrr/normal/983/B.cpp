// Tima the best
#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=5123,inf=1e8,mod=1e9+7,block=200,N=1e5+123;
int q,n,a[maxn],dp[maxn][maxn],t[4*maxn],ans[N];
pair< pair< int ,int > , int > b[N];
void up(int v,int tl, int tr,int pos,int val){
	if(tl==tr){
		t[v]=max(t[v],val);
		return;
	}
	int tm=(tl+tr)/2;
	if(pos<=tm)
		up(v+v,tl,tm,pos,val);
	else
		up(v+v+1,tm+1,tr,pos,val);
	t[v]=max(t[v+v],t[v+v+1]);	
}
int get(int v,int tl, int tr,int l,int r){
	if(l>r)
		return 0;
	if(tl==l && tr==r)
		return t[v];
	int tm=(tl+tr)/2;
	return max( get(v+v,tl,tm,l,min(tm,r)) , get(v+v+1,tm+1,tr,max(tm+1,l),r ) );
}

int main(){
	#ifdef LOCAL
    	freopen ("test.in", "r", stdin);
	#endif
	scanf("%d",&n);     
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
        dp[i][i]=a[i];
	}
	for(int len=2;len<=n;len++)
		for(int l=1;l+len-1<=n;l++)
			dp[l][l+len-1]=(dp[l][l+len-1-1]^dp[l+1][l+len-1]);
	scanf("%d",&q);
    for(int i=1;i<=q;i++){
		scanf("%d%d",&b[i].f.s,&b[i].f.f);
		b[i].s=i;
	}
    sort(b+1,b+1+q);
    for(int r=1,j=1;r<=n;r++){

    	for(int l=1;l<=r;l++)
    		up(1,1,n,l,dp[l][r]);	
    	while(j<=q && b[j].f.f==r){
    		int l=b[j].f.s;
    		ans[b[j].s]=get(1,1,n,l,r);
    		j++;
    	}
    }	
    for(int i=1;i<=q;i++)
		printf("%d\n",ans[i]);
}