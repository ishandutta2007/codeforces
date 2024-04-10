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
const ll maxn=1e5+123,inf=1e8,mod=1e9+7,block=200,N=1000+123;
ll n,p,q,b,g;
         	
int main(){
	#ifdef LOCAL
		freopen ("test.in", "r", stdin);
	#endif
	IOS
	cin>>n;
	while(n--){
		cin>>p>>q>>b;
		if(p==0){
			cout<<"Finite"<<endl;
			continue;
		}
		q/=__gcd(p,q);
		while(true){
			g=__gcd(q,b);
			if(g==1)
				break;
			if(g>1e5){
				q/=g;
				continue;
			}
			for(int i=2;i*i<=g;i++)
				if(g%i==0){
					while(q%i==0)
						q/=i;
					while(q%(g/i)==0)
						q/=(g/i);
				}
			while(q%g==0)
				q/=g;
        	break;    
		}
		//cout<<q<<" "<<b<<endl;;
		if(q==1)           
			cout<<"Finite"<<endl;
		else
			cout<<"Infinite"<<endl;
	}                                  
}