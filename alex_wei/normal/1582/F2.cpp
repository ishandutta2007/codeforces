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

const int N=1e6+5;
const int B=1<<13;

int n,a[N],ans[B],las[B];
vint buc[B];
int main(){
	cin>>n,mem(ans,0x3f,B),ans[0]=0;
	for(int i=1,a;i<=n;i++)cin>>a,buc[a].pb(i);
	for(int i=1;i<B;i++){
		static int c[B];
		cpy(c,ans,B);
		for(int j=0;j<B;j++){
			int p=lower_bound(buc[i].begin(),buc[i].end(),ans[j])-buc[i].begin(); 
			if(p<buc[i].size())cmin(c[j^i],buc[i][p]);
		}
		cpy(ans,c,B);
	}
	int cnt=0;
	for(int i=0;i<B;i++)cnt+=ans[i]<N;
	cout<<cnt<<endl;
	for(int i=0;i<B;i++)
		if(ans[i]<N)cout<<i<<" ";
    return 0;
}