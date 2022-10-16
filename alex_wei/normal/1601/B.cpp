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

const int N=3e5+5;

int n,a[N],b[N],fr1[N],fr2[N];
int f[N],dis1[N],dis2[N];
set <int> s1,s2;
deque <pii> q;
void path(int id,int type){
	if(id==0)return;
	path(type==2?fr1[id]:fr2[id],type==2?1:2);
	if(type==1)cout<<id<<" ";
}
void solve(){
	cin>>n,mem(dis1,0x3f,N),mem(dis2,0x3f,N);
	dis1[n]=0,q.push_back({n,0});
	for(int i=1;i<=n;i++)cin>>a[i],s1.insert(i),s2.insert(i);
	s2.erase(n);
	for(int i=1;i<=n;i++)cin>>b[i];
	while(!q.empty()){
		pii t=q.front(); q.pop_front();
		int id=t.fi;
		if(t.se==1){
			int p=id+b[id];
			if(s2.find(p)!=s2.end()){
				s2.erase(p),dis1[p]=dis2[id];
				q.push_front({p,0}),fr1[p]=id;
			}
		}
		else{
			int p=id-a[id];
			if(p==0){
				cout<<dis1[id]+1<<endl;
				path(id,2),cout<<0<<endl,exit(0);
			}
			while(!s1.empty()){
				auto it=s1.lower_bound(p);
				if(it==s1.end())break;
				if(*it>id)break;
				int qq=*it;
				s1.erase(qq),dis2[qq]=dis1[id]+1;
				q.push_back({qq,1}),fr2[qq]=id;
			}
		}
	}
	puts("-1"); 
}

int main(){
	int T=1;
	while(T--)solve();
    return 0;
}