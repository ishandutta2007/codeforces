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
const int K=555;

ll t,n,a[N],s[N];
ll f[N][K];
void solve(){
	cin>>n,mem(f,0,n+5);
	for(int i=1;i<=n;i++)cin>>a[i],s[i]=s[i-1]+a[i];
	for(int i=n;i;i--)
		for(int j=1;j<K&&i+j-1<=n;j++){
			f[i][j]=f[i+1][j];
			if(j==1)cmax(f[i][j],a[i]);
			else if(s[i+j-1]-s[i-1]<f[i+j][j-1])cmax(f[i][j],s[i+j-1]-s[i-1]);
		}
	for(int i=K-1;i;i--)if(f[1][i])return cout<<i<<endl,void();
}

int main(){
	int T; cin>>T;
	while(T--)solve();
    return 0;
}