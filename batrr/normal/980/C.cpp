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
const ll maxn=2e5+123,inf=1e18,mod=1e9+7;
int n,a[maxn],c[maxn],k;

int main(){
	for(int i=0;i<500;i++)
		c[i]=-1;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		if(c[a[i]]!=-1)
			continue;
		int x=a[i];
		for(int len=1;len<=k && x-len+1>=0;len++){
			if(c[x-len+1]==-1){
				
				if( (len==k || x-len+1==0) )
					for(int j=x-len+1;j<=x;j++)
						c[j]=x-len+1;
			
			}else{
				
				if( x-c[x-len+1]+1<=k )
					for(int j=x-len+2;j<=x;j++)
						c[j]=c[x-len+1];
			    else
					for(int j=x-len+2;j<=x;j++)
						c[j]=x-len+2;
				break;
			}
		}
	
	}
	for(int i=1;i<=n;i++)
		cout<<c[a[i]]<<" ";	
}