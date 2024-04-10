#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n,m,a[1005];
long double p[10005];
mt19937 r(time(0));
string s;
int main(){
	p[0]=1;
	for(int i=1;i<=20;++i)p[i]=p[i-1]*0.6;
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		long double x=0,y=0;
		cin>>s;
		for(int j=0;j<n;++j){
			if(s[j]=='1')y+=p[a[j]];
			else x+=p[a[j]];
		}
		if((r()%orz)*1.0/orz<x/(x+y))cout<<0<<endl;
		else cout<<1<<endl;
		fflush(stdout);
		int k;
		cin>>k;
		if(k==0){
			for(int j=0;j<n;++j)if(s[j]=='1')++a[j];
		}
		else{
			for(int j=0;j<n;++j)if(s[j]=='0')++a[j];
		}
		bool ok=1;
		for(int j=0;j<n;++j)if(!a[j])ok=0;
		if(ok){
			for(int j=0;j<n;++j)--a[j];
		}
	}
    return 0;
}