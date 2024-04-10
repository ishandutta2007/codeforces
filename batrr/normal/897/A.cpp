#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <cstdio> 
#include <deque>
#include <map>
#include <iomanip>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ull unsigned long long
#define ll long long
#define GG(a) cout<<"Bug is here!!!"<<a<<endl
using namespace std;
const int m=1e9+7,maxn=1e6+123;                                
int n,a[maxn],ans,q,w;
string s;
/*
ll fact[maxn],revfact[maxn];
ll binpow(ll a, ll t){
	if(t==1)
		return a;
	ll c=binpow(a,t/2);
	if(t%2==0)
		return c*c%m;
	else
		return c*c%m*a%m;		
}                                            
ll c(ll k,ll n){
	return fact[n]*revfact[k]%m*revfact[n-k]%m;
}              */                         
int main(){                               /*
	fact[0]=1;
	for(int i=1;i<maxn;i++)
		fact[i]=fact[i-1]*i%m;
	revfact[maxn-1]=binpow(fact[maxn-1],m-2);
	for(int i=maxn-2;i>=0;i--)
		revfact[i]=revfact[i+1]*(i+1)%m;*/
    int len;
    cin>>len>>n>>s
    ;
    char v,t;
    int l,r;
    for(int i=0;i<n;i++){
    	cin>>l>>r>>v>>t;
    	for(int j=l-1;j<r;j++)
    		if(s[j]==v)
    			s[j]=t;    
    }
    cout<<s;
	return 0;
}