#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define sortv(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))

char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;

#ifdef __WIN64
	#define gc getchar()
#else
	#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
#endif
#define pc(x) (*O++=x)
#define flush() fwrite(obuf,O-obuf,1,stdout)

inline int read(){
	int x=0,sign=0; char s=getchar();
	while(!isdigit(s))sign|=s=='-',s=getchar();
	while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=getchar();
	return sign?-x:x;
}
void print(int x){
	if(x>9)print(x/10);
	pc(x%10+'0');
}

const int N=1e4+5;
struct seg{
	int l,r;
	bool operator < (const seg &v) const {
		return r<v.r;
	}
}c[N];
int n,pd[N<<1];
vector <int> ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i].l>>c[i].r;
		if(c[i].l>c[i].r)swap(c[i].l,c[i].r);
	}
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++){
		bool need=1;
		for(int j=c[i].l;j<=c[i].r;j++)if(pd[j+N])need=0;
		if(need)pd[c[i].r+N]=1,ans.push_back(c[i].r);
	}
	cout<<ans.size()<<endl;
	for(auto it:ans)cout<<it<<" ";
    return 0;
}