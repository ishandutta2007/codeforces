#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=2e6;
int dp[N],n,tr1[N],tr2[N],a[N],tr[N<<2];
inline void add1(int x,int y,int pos){
	while(x<=n){
	  if(y>tr1[x]){
	      tr1[x]=max(tr1[x],y);
	      tr2[x]=pos;
	  }
	  else if(y==tr1[x]) tr2[x]=min(tr2[x],pos);
	  x+=x&-x;
    }  
}
inline int query1(int x){
	int ans=0,ans1=1e9;
	while(x){
		if(tr1[x]>ans){
	        ans=max(tr1[x],ans);
	        ans1=tr2[x];
	    }
	    else if(tr1[x]==ans)ans1=min(ans1,tr2[x]);
		x-=x&-x;
	}
	return ans1;
}
void build(int cnt,int l,int r){
	if(l==r){
		tr[cnt]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(cnt<<1,l,mid);
	build(cnt<<1|1,mid+1,r);
	tr[cnt]=max(tr[cnt<<1],tr[cnt<<1|1]); 
}
int query(int cnt,int l,int r,int L,int R){
	if(L>R)return -1e9;
	if(l>=L&&r<=R)return tr[cnt];
	int mid=(l+r)>>1,ans=0; 
	if(mid>=L)ans=max(ans,query(cnt<<1,l,mid,L,R));
	if(mid<R)ans=max(ans,query(cnt<<1|1,mid+1,r,L,R));
	return ans;
}
int main()
{
	int T;
    scanf("%d",&T);
    while(T--){
    	scanf("%d",&n);
    	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    	build(1,1,n);
    	for(int i=0;i<=n;++i)tr1[i]=0,tr2[i]=1e9;
    	int ans=0;
    	for(int i=1;i<=n;++i){
    		int x=query1(a[i]);
			dp[i]=1;
    		if(x!=1e9){
    		dp[i]=max(dp[i],dp[x]+1);
    		int mx=query(1,1,n,x+1,i-1);
    	//	cout<<x<<" "<<mx<<" ";
    		if(mx>=max(a[x],a[i])){
    			dp[i]=max(dp[i],dp[x]+2);
    		}
    	    }
    	    else{
    	    	if(query(1,1,n,1,i-1)>a[i])
    	    	    dp[i]=max(dp[i],2);
    	    }
    	//    cout<<i<<" "<<dp[i]<<endl;
    	    add1(a[i],dp[i],i);
    	    ans=max(ans,dp[i]);
    	    if(query(1,1,n,i+1,n)>a[i])
			   ans=max(ans,dp[i]+1);
    	}
    	printf("%d\n",ans);
    }
	return 0;
	
}