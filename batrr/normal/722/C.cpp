#include <bits/stdc++.h>

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

using namespace std;

const int maxn=3e5+123;

int n,a[maxn],p[maxn],l[maxn],r[maxn];
ll sum[maxn],ans[maxn],cur;
bool was[maxn];
int main(){
    //freopen ("test.in", "r", stdin);


    cin>>n;
    for(int i=1;i<=n;i++)
    	cin>>a[i];
    for(int i=1;i<=n;i++)
    	cin>>p[i];
	for(int i=1;i<=n;i++){
		l[i]=r[i]=i;
		sum[i]=a[i];
	}
	for(int i=n;i>=1;i--){
		int x=p[i];
		bool bl,br;
		bl=br=0;
		if( was[x-1] )
			bl=1;
		if( was[x+1] )
			br=1;
		if( bl && br ){
			ll s=sum[x-1]+sum[x+1]+a[x];
			r[l[x-1]]=r[x+1];
			l[r[x+1]]=l[x-1];
			sum[r[x+1]]=sum[l[x-1]]=s;
			cur=max(cur,s);		
		}
		if( bl && !br){
			ll s=sum[x-1]+a[x];
			r[l[x-1]]=x;
			l[x]=l[x-1];
			sum[x]=sum[l[x-1]]=s;
			cur=max(cur,s);		
		}
        
        if( !bl && br){
			ll s=sum[x+1]+a[x];
			r[x]=r[x+1];
			l[r[x+1]]=x;
			sum[x]=sum[r[x+1]]=s;
			cur=max(cur,s);		
		}
		if( !bl && !br){
			ll s=a[x];
        	cur=max(cur,s);		
		}
		was[x]=1;
		ans[i-1]=cur;
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<endl;
}