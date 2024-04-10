// Tima the best
#include <bits/stdc++.h>

#define ll long long                   
#define ld long double                
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=1e6+123,inf=1e8,mod=1e9+7,block=200,N=2053;
int n,a[maxn],ans,p[maxn];
int main(){
	#ifdef LOCAL
    	freopen ("test.in", "r", stdin);
	#endif 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[a[i]]=i;	
	}
	for(int i=1;i<=n;i++){
		if(a[i]==i)
			continue;
		p[a[i]]=p[i];
		swap(a[i],a[p[i]]);
		p[i]=i;
		ans++;
	}
	//cout<<ans<<endl;
	if( (n%2-ans%2)%2==0 )            
		cout<<"Petr"<<endl;
	else
		cout<<"Um_nik"<<endl;
}