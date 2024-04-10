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

int n,a[N];
void solve(int a,int b){cout<<b<<" "<<-a<<" ";}
void solve(int a,int b,int c){
	if(a==b&&b==c)cout<<"1 1 -2 ";
	else if(a==c){
		int coef=-b,x,y;
		if(coef<0)x=1,y=coef-1;
		else x=-1,y=coef+1;
		cout<<x<<" "<<a<<" "<<y<<" ";
	} else if(a==-c){
		int coef=b,x,y;
		if(coef<0)y=-1,x=coef-1;
		else y=1,x=coef+1;
		cout<<x<<" "<<-a<<' '<<y<<" ";
	}
	else if(abs(c-a)<=1e4)
		cout<<b<<" "<<c-a<<" "<<-b<<" ";
	else cout<<-b<<' '<<c+a<<" "<<-b<<" ";
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n%2==0)for(int i=1;i<=n;i+=2)solve(a[i],a[i+1]);
	else{
		solve(a[1],a[2],a[3]);
		for(int i=4;i<=n;i+=2)solve(a[i],a[i+1]);
	}
	cout<<endl;
}

int main(){
	int T; cin>>T;
	while(T--)solve();
    return 0;
}