#include <bits/stdc++.h>

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=1e5+12+300,inf=1e9,LOG=18,mod=1e9+7,block=316;
ll n,q,a[maxn],b[maxn],add[maxn/block],sum[maxn/block],all[maxn];
void calc1(int i){
	if(all[i]==0)
		return;
	for(int j=0;j<block;j++){
		a[i*block+j]=all[i];                   
	}
	all[i]=0;
}      
void up(int l, int r,ll x){
	int bl=l/block;
    int br=r/block;
    if(bl==br){
		calc1(bl);
  		for(int i=l;i<=r;i++){
    		b[i]+=abs(a[i]-x);
    		sum[bl]+=abs(a[i]-x);
    		a[i]=x;
    	}
    }else{        
    	calc1(bl);
    	calc1(br);
    	for(int i=l;i<(bl+1)*block;i++){
    		b[i]+=abs(a[i]-x);
    		sum[bl]+=abs(a[i]-x);
    		a[i]=x;
    	}
        for(int i=br*block;i<=r;i++){
    		b[i]+=abs(a[i]-x);
    		sum[br]+=abs(a[i]-x);
    		a[i]=x;
    	}
    	for(int i=bl+1;i<br;i++){
    		
    		if(all[i]!=0){
    			add[i]+=abs(all[i]-x);
    			sum[i]+=abs(all[i]-x)*block;
    			all[i]=x;
    			continue;
    		}
    		for(int j=0;j<block;j++){
    			b[i*block+j]+=abs(a[i*block+j]-x);
    			sum[i]+=abs(a[i*block+j]-x);
    			a[i*block+j]=x;
    		}
    		all[i]=x;
        	
        }
    }

}
ll get(int l,int r){
	int bl=l/block;
    int br=r/block;
    ll res=0;
    if(bl==br){
		calc1(bl);
  		for(int i=l;i<=r;i++)
    		res+=b[i]+add[bl];
    }else{        
    	calc1(bl);
    	calc1(br);
    	for(int i=l;i<(bl+1)*block;i++)
    		res+=b[i]+add[bl];
    	for(int i=br*block;i<=r;i++)
    		res+=b[i]+add[br];
    	for(int i=bl+1;i<br;i++)
    		res+=sum[i];
    }
	return res;
}
int main(){
	#ifdef LOCAL
		freopen ("test.in", "r", stdin);
 	#endif
 	scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
 		a[i]=i;   
  	while(q--){
 		int type,l,r,x;
 		scanf("%d",&type);
        if(type==1){
 			scanf("%d%d%d",&l,&r,&x);
            up(l,r,x);
 		}else{
 			scanf("%d%d",&l,&r);
 			printf("%lld\n",get(l,r));
  		}
 	}
}