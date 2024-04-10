#include <bits/stdc++.h> ////////////////////
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
#define mem(x,v,s) memset(x,v,sizeof(x[0])*(s))
#define cpy(x,y,s) memcpy(x,y,sizeof(x[0])*(s))
   
inline int read(){
    int x=0,sgn=0; char s=getchar();
    while(!isdigit(s))sgn|=s=='-',s=getchar();
    while(isdigit(s))x=x*10+s-'0',s=getchar();
    return sgn?-x:x;
}

template <class T> void cmin(T &a,T b){a=a<b?a:b;}
template <class T> void cmax(T &a,T b){a=a>b?a:b;}

const int N=200+5;

ll n,l,v[N],node;
struct mat{
	ll a[N][N];
	mat(){mem(a,0xcf,N);}
	friend mat operator * (mat x,mat y){
		mat z;
		for(int i=0;i<=node;i++)
			for(int j=0;j<=node;j++)
				for(int k=0;k<=node;k++)
					cmax(z.a[i][j],x.a[i][k]+y.a[k][j]);
		return z;
	}
}base,vec;

int son[N][26],fa[N],val[N];
void ins(string s,int v){
	int p=0;
	for(auto it:s){
		if(!son[p][it-'a'])son[p][it-'a']=++node;
		p=son[p][it-'a'];
	} val[p]+=v;
}
void build(){
	queue <int> q;
	for(int i=0;i<26;i++)if(son[0][i])q.push(son[0][i]);
	while(!q.empty()){
		int t=q.front(); q.pop();
		for(int i=0;i<26;i++)
			if(son[t][i])fa[son[t][i]]=son[fa[t]][i],q.push(son[t][i]);
			else son[t][i]=son[fa[t]][i];
		val[t]+=val[fa[t]];
	}
}
int main(){
	cin>>n>>l;
	for(int i=1;i<=n;i++)cin>>v[i];
	for(int i=1;i<=n;i++){
		string s; cin>>s;
		ins(s,v[i]);
	}
	build();
	for(int i=0;i<=node;i++)
		for(int j=0;j<26;j++)
			base.a[i][son[i][j]]=val[son[i][j]];
	vec.a[0][0]=0;
	while(l){
		if(l&1)vec=vec*base;
		base=base*base,l>>=1;
	}
	ll ans=0;
	for(int i=0;i<=node;i++)cmax(ans,vec.a[0][i]);
	cout<<ans<<endl;
    return 0;
}