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
int n,k;
string s1,s2;
int main(){
	cin>>n>>k; 
	for(int i=1;i<=n;i++)
		s1+='.',s2+='.';
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)
		cout<<'.';
	cout<<endl;
	for(int i=1;i<n/2;i++)
		if(k>=2)
			s1[i]='#',s1[n-1-i]='#',k-=2;
    for(int i=1;i<n/2;i++)
		if(k>=2)
			s2[i]='#',s2[n-1-i]='#',k-=2;
	if(k>0)
		s1[n/2]='#',k--;
	if(k>0)
		s2[n/2]='#',k--;
	
	cout<<s1<<endl<<s2<<endl;
	for(int i=1;i<=n;i++)
		cout<<'.'; 
	cout<<endl;
}