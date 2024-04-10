/*
	Templates start.
	Powered by c++11.
	Author : Alex_Wei.
*/

//#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

// IO templates.

char buf[1ll<<21],*p1=buf,*p2=buf,obuf[1ll<<23],*O=obuf;
#ifdef __WIN64
	#define gc getchar()
#else
	#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1ll,1ll<<20,stdin),p1==p2)?EOF:*p1++)
#endif
#define pc(x) (*O++=x)
#define flush() fwrite(obuf,O-obuf,1ll,stdout)

inline int read(){
	int x=0,sign=0; char s=getchar();
	while(!isdigit(s))sign|=s=='-',s=getchar();
	while(isdigit(s))x=(x<<1ll)+(x<<3)+(s-'0'),s=getchar();
	return sign?-x:x;
}
void print(int x) {if(x>9)print(x/10); pc(x%10+'0');}

#define ll long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))

/*
	Templates end.
	Please give me more points.
*/

ll n,rem;

ll calc(ll l,ll r,ll num,ll tot){
//	cout<<l<<" "<<r<<" "<<num<<" "<<tot<<" "<<rem<<endl;
//	system("pause");
	if(l==r)return l;
	if(l==r-1ll)return l;
	ll sz=(r-l)/4,a=l+sz,b=l+sz*2,c=l+sz*3,qwq=tot/4;
	if(rem==1ll){
		if(num<=qwq)return calc(l,a,num,qwq);
		if(num<=qwq*2)return calc(a,b,num-qwq,qwq);
		if(num<=qwq*3)return calc(b,c,num-qwq*2,qwq);
		return calc(c,r,num-qwq*3,qwq);
	}
	if(rem==2){
		if(num<=qwq)return calc(l,a,num,qwq);
		if(num<=qwq*2)return calc(b,c,num-qwq,qwq);
		if(num<=qwq*3)return calc(c,r,num-qwq*2,qwq);
		return calc(a,b,num-qwq*3,qwq);
	}
	if(rem==3){
		if(num<=qwq)return calc(l,a,num,qwq);
		if(num<=qwq*2)return calc(c,r,num-qwq,qwq);
		if(num<=qwq*3)return calc(a,b,num-qwq*2,qwq);
		return calc(b,c,num-qwq*3,qwq);
	}
}

void solve(){
	cin>>n;
	if(n<4){
		cout<<n<<endl;
		return;
	}
	ll div=(n-1ll)/3+1ll; rem=(n-1ll)%3+1ll;
	ll bit=-1ll;
	while(n)n>>=2,bit++;
	cout<<calc((rem<<(bit*2)),rem+1ll<<(bit*2),div-((1ll<<(bit*2))-1ll)/3,1ll<<(bit*2))<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}