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
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=2e5+123,inf=1e9,mod=1e9+7;

int n,x[maxn];
ll t,a[maxn],b[maxn],c[maxn];
int main(){
	scanf("%d%lld",&n,&t);  
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]);
	a[n+1]=1.5e18;	     
   	for(int i=1;i<=n;i++){
   		if( x[i]<x[i-1] || x[i]<i ){
   			puts("No");
   			return 0;
   		}
   		b[x[i]]=a[x[i]+1]-1;
   		c[i]++;
   		c[x[i]]--;
   	}
   	for(int i=n;i>=1;i--)
   		if(b[i]==0)
   			b[i]=b[i+1]-1;
                        
   	for(int i=1;i<n;i++)
   		if( b[i]>=b[i+1] ){
   			puts("No");
   			return 0;
   		}

   	for(int i=1;i<=n;i++)
   		c[i]+=c[i-1];
   	for(int i=1;i<=n;i++){
   		if( c[i] ){
   			if( i!=n && b[i]<a[i+1]){
   				puts("No");
   				return 0;
   			}
   		}else{
   			if( b[i]<a[i] || (i!=n && b[i]>=a[i+1]) ){
   				puts("No");
   				return 0;
   			}
   		}
   	}
   
	
	puts("Yes");
   	for(int i=1;i<=n;i++)
		printf("%lld ",b[i]+t);
	return 0;
}