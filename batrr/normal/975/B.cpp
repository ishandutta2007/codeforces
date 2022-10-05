#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define nm "A" 
#define stdi freopen(nm".in","r",stdin);
#define stdo freopen(nm".out","w",stdout);
#define IO stdi stdo                   
#define ll long long                   
#define ld long double                                                                                                           
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=5e5+123,MX=1e9,inf=1e9,block=2;
ll n,a[maxn],b[maxn],ans;
int main(){
	n=14;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++){
		if(a[i]==0)
			continue;
		for(int j=0;j<n;j++)
			if(i==j)
				b[j]=a[i]/14;
			else
				b[j]=a[j]+a[i]/14;
		ll sum=0,x=a[i]%14,j=i+1;
		while(x--){
			b[j%n]++;
			j++; 
		}
   		for(int j=0;j<n;j++)
   			if(b[j]%2==0)
   				sum+=b[j];
   		 ans=max(ans,sum);
   	}
   	cout<<ans;
}