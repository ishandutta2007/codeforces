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

const int N=2e5+5;

int n,a[N],buc[N];
void solve(){
	cin>>n;
	int num=0;
	for(int i=1;i<=n;i++)cin>>a[i],buc[i]=0;
	for(int i=0;i<30;i++){
		int c=0;
		for(int j=1;j<=n;j++)c+=a[j]>>i&1;
		if(c!=0)num++;
		for(int j=1;j*j<=c;j++)
			if(c%j==0){
				buc[j]++;
				if(j*j!=c)buc[c/j]++;
			}
	}
	for(int i=1;i<=n;i++)
		if(buc[i]==num)cout<<i<<" ";
	cout<<endl;
}

int main(){
	int T; cin>>T;
	while(T--)solve();
    return 0;
}