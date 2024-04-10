#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define reg register
const int maxn=10005;
char buffer[maxn],*S,*T;
inline char Get_Char(){
    if(S==T){
        T=(S=buffer)+fread(buffer,1,maxn,stdin);
        if(S==T)return EOF;
    }
    return *S++;
}
inline int read(){
    reg char c;
    reg int re=0,f=0;
    for(c=Get_Char();c<'0' or c>'9';c=Get_Char())if(c=='-')f=1;
    for(;c>='0' and c<='9';)re=(re<<1)+(re<<3)+(c-'0'),c=Get_Char();
    if(f)return -re;
    return re;
}
inline void read(int&x){
    reg char c;
    reg int re=0,f=0;
    for(c=Get_Char();c<'0' or c>'9';c=Get_Char())if(c=='-')f=1;
    for(;c>='0' and c<='9';)re=(re<<1)+(re<<3)+(c-'0'),c=Get_Char();
    if(f)x=-re;
    else x=re;
}
inline void read(ll&x){
    reg char c;
    reg ll re=0,f=0;
    for(c=Get_Char();c<'0' or c>'9';c=Get_Char())if(c=='-')f=1;
    for(;c>='0' and c<='9';)re=(re<<1)+(re<<3)+(c-'0'),c=Get_Char();
    if(f)x=-re;
    else x=re;
}
const int mxn=2e5+5;
ll n,a[mxn],k;
inline void solve(){
	map<int,int>mc;
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>a[i],mc[a[i]]=1;
	for(int i=1;i<=n;++i)if(mc[a[i]-k]){
		cout<<"YES\n";
		return;
	}
	cout<<"NO\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T=1;
	cin>>T;
	for(;T--;)solve();
	return (0-0);
}