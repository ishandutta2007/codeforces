//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <climits>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <complex>
#include <random>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
#define itn int
#define nit int
#define ll long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define re register
#define ri re int
#define il inline
#define pii pair<int,int>
#define cp complex<double>
#define vi vector<int>
#define ull unsigned long long
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
using namespace std;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
namespace fastIO {
	template<class T>
	inline void read(T &x) {
		x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		if(fu)x=-x;
	}
	inline int read() {
		int x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		return fu?-x:x;
	}
	template<class T,class... Args>
	inline void read(T& t,Args&... args) {
		read(t);
		read(args...);
	}
	char _n_u_m_[40];
	template<class T>
	inline void write(T x) {
		if(x==0) {
			putchar('0');
			return;
		}
		T tmp = x > 0 ? x : -x ;
		if( x < 0 ) putchar('-') ;
		register int cnt = 0 ;
		while( tmp > 0 ) {
			_n_u_m_[ cnt ++ ] = tmp % 10 + '0' ;
			tmp /= 10 ;
		}
		while( cnt > 0 ) putchar(_n_u_m_[ -- cnt ]) ;
	}
	template<class T>
	inline void write(T x ,char ch) {
		write(x);
		putchar(ch);
	}
}
using namespace fastIO;
int n;
bool a[2002][2002];
char c[2002][2002];
inline vector<pii > orz(vector<pii >p) {
	int pos=p.size()/2;
	vector<pii >res;
	F(i,1,pos-1)res.push_back({p.back().first,p[i].first});
	F(i,pos,p.size()-2)res.push_back({p[0].first,p[i].first});
	res.push_back({p[0].first,p.back().first});
	return res;
}
inline vector<pii > orz(vector<pii >p,vector<pii >v) {
	vector<pii >res;
	int now=0;
	F(i,0,v.size()-1){
		if(v[i]==p[now]){
			++now;
			F(j,i+1,v.size()-1){
				if(v[j]==p[now]){
					auto temp=orz(vector<pii >(p.begin()+i,p.begin()+j+1));
					res.insert(res.end(),temp.begin(),temp.end());
					break;
				}
			}
		}
	}
	return res;
}
int lp[2002],rp[2002];
inline vector<pii >solve(vector<pii >p) {//for(auto i:p)cerr<<i.first<<" "<<i.second<<endl;cerr<<endl;
	if(p.size()<=1)return {};
	UF(i,p.size()-1,0)F(j,i+1,p.size()-1)if(a[p[i].first][p[j].second]) {//cerr<<p[i].first<<"k"<<p[j].second<<endl;
		int lst=i;
		vector<pii >qwq;
		if(qwq.empty()) {
			auto temp=orz(vector<pii >(p.begin()+i,p.begin()+j+1));
			int fir=p[i].first;
			auto q=p;
			q.erase(q.begin()+i,q.begin()+j);
			q[i].first=fir;
			auto nxt=solve(q);//for(auto i:p)cerr<<i.first<<" "<<i.second<<endl;
			int l=j,r=i;//cerr<<"K";
			F(i,0,n+1)lp[i]=l,rp[i]=r;//cerr<<i<<" "<<j<<endl;
			F(k,0,i-1){//cerr<<k<<endl;
				F(x,i,l-1)if(a[p[k].first][p[x].second]){
					l=x;
					break;
				}
				lp[p[k].first]=p[l].first;
			}//cerr<<"G";
			UF(k,p.size()-1,i+1){
				UF(x,j,r+1)if(a[p[x].first][p[k].second]){//cerr<<p[x].first<<"v"<<p[k].first<<endl;
					r=x;
					break;
				}
				rp[p[k].first]=p[r].first;
			}
			for(auto &x:nxt) {
				if(x.first==p[i].first)swap(x.first,x.second);
				if(x.second==p[i].first) {
					if((x.first<p[i].first))x.second=lp[x.first];
					else x.second=rp[x.first];
				}
			}
			temp.insert(temp.end(),nxt.begin(),nxt.end());
			return temp;
		} 
	}
}
int main() {//auto temp=orz({{1,1},{2,2},{3,3}},{{1,1},{2,2},{3,3}});for(auto i:temp)cerr<<i.first<<" "<<i.second<<endl;
	F(iakioi,1,read()) {
		read(n);
		F(i,1,n)scanf("%s",c[i]+i);
		F(i,1,n)F(j,i,n)a[i][j]=c[i][j]-'0';
		vector<pii >p;
		F(i,1,n)p.push_back({i,i});
		auto ans=solve(p);
		for(auto i:ans) {
			write(i.first,' ');
			write(i.second,'\n');
		}
	}
	return 0;
}
/*
1
4
1001
111
11
1
101
11
1
*/