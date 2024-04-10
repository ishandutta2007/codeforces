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
string s;
int a,b;
int main(){
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='-')
			a++;
		else
			b++;
	if(b==0 || a%b==0)
		cout<<"YES";
	else
		cout<<"NO";	
}