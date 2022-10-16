#include <bits/stdc++.h>
using namespace std;

#define db double
#define ll long long
#define ld long double
#define uint unsigned int
#define ull unsigned long long
#define vint vector <int>
#define vpii vector <pii>

#define pii pair <int,int>
#define fi first
#define se second
#define pb emplace_back
#define all(x) begin(x),end(x)
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
#define mem(x,v,s) memset(x,v,sizeof(x[0])*(s))
#define cpy(x,y,s) memcpy(x,y,sizeof(x[0])*(s))

char buf[1<<21],*p1=buf,*p2=buf;
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read(){
    int x=0,sgn=0; char s=gc;
    while(!isdigit(s))sgn|=s=='-',s=gc;
    while(isdigit(s))x=x*10+s-'0',s=gc;
    return sgn?-x:x;
}

template <class T1,class T2> void cmin(T1 &a,T2 b){a=a<b?a:b;}
template <class T1,class T2> void cmax(T1 &a,T2 b){a=a>b?a:b;}

const int N=1e5+5;

int n;
char s[N];
int solve(char *s,char ch){
	int l=1,r=n,ans=0;
	while(l<r){
		if(s[l]!=s[r]){
			if(s[l]==ch)l++;
			else if(s[r]==ch)r--;
			else return 1e9;
			ans++;
		} else l++,r--;
	}
	return ans;
}
void solve(){
	cin>>n>>s+1;
	for(int i=1;i<<1<=n;i++){
		if(s[i]!=s[n-i+1]){
			int r=min(solve(s,s[i]),solve(s,s[n-i+1]));
			if(r>N)puts("-1");
			else cout<<r<<endl;
			return; 
		}
	}
	cout<<0<<endl;
}

int main(){
	int T; cin>>T;
	while(T--)solve();
    return 0;
}