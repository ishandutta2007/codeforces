#include<bits/stdc++.h>
#include<vector>
#include<map>
#include<cassert>
#include<iostream>
#include<algorithm>
#define pii pair<int,int>
#define F(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
using namespace std;
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
		if(x==0){
			putchar('0');
			return;
		}
		T tmp = x > 0 ? x : -x ;
		if( x < 0 ) putchar('-') ;
		int cnt = 0 ;
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
struct S{
	int len;
	vector<pii >v;
	inline int size(){
		return v.size();
	}
	inline pii& operator[](int x){
		return v[x];
	}
}O;
inline void split(S x,int k,S &a,S &b){
	a=b=O;
	if(x.len){
		F(i,0,x.size()-1){
			if(a.len+x[i].second-x[i].first+1<k){
				a.v.push_back(x[i]);
				a.len+=x[i].second-x[i].first+1;
			}else{
				a.v.push_back(make_pair(x[i].first,x[i].first+k-a.len-1));
				b.v.push_back(make_pair(x[i].first+k-a.len,x[i].second));
				a.len=k;
				F(j,i+1,x.size()-1)b.v.push_back(x[j]);
				b.len=x.len-k;
				return;
			}
		}
	}
}
inline bool in(S x,int p){
	for(auto i:x.v)if(i.first<=p&&p<=i.second)return true;
	return false;
}
inline S operator+(S x,S y){
	for(auto i:y.v)x.v.push_back(i);
	x.len+=y.len;
	sort(x.v.begin(),x.v.end());
	return x;
}
/*
inline void dfs(S x,S y,int p){
	if(x.len+y.len<=2)return;
	if(!(x.len==2&&y.len==1)){
		S a,b,c,d;
		split(x,x.len>>1,a,b);
		split(y,(y.len+1)>>1,c,d);
		if(in(x,p)){
			if(in(a,p)){
				if(send(0)==0){
					dfs(a+c,b,p);
				}else{
					dfs(b+d,a,p);
				}
				return;
			}
			if(send(1)==1)dfs(b+d,a,p);
			else dfs(a+c,b,p);
		}else{
			if(in(c,p)){
				if(send(0)==0){
					dfs(a+c,b,p);
				}else assert(false);
				return;
			}
			if(send(1)==1)dfs(b+d,a,p);
			else assert(false);
		}
	}else{
		if(in(x,p)){
			if(send(0)==0)dfs(x,O,p);
			else dfs(y,x,p);
		}else{
			if(send(1)==1)dfs(y,x,p);
			else assert(false);
		}
	}
}
*/
inline bool receive(S s){int sum=0;
	putchar('?');putchar(' ');for(auto i:s.v)sum+=i.second-i.first+1;write(sum,' ');
	for(auto i:s.v)F(j,i.first,i.second)write(j,' ');putchar('\n');fflush(stdout);
	string t;cin>>t;return t=="YES";
}
inline void dbg(S s){
//	putchar('?');putchar(' ');
	for(auto i:s.v)F(j,i.first,i.second)write(j,' ');putchar('\n');fflush(stdout);
	
}
inline pii solve(S x,S y){//dbg(x);dbg(y);
	if(x.len+y.len<=2){
		x=x+y;
		vector<int>res;
		res.clear();
		for(auto i:x.v)F(j,i.first,i.second)res.push_back(j);
		if(!(res.size()==1||res.size()==2))while(true);
		if(res.size()==1)return make_pair(res.back(),res.back());
		return make_pair(res[0],res[1]);
	}
	if(!(x.len==2&&y.len==1)){
		S a,b,c,d;
		split(y,(y.len+1)>>1,c,d);
		if(!(y.len&1)||(x.len&1)||!x.len)split(x,x.len>>1,a,b);
		else split(x,(x.len>>1)-1,a,b);
		int k=receive(a+c);
		if(k==1)return solve(a+c,b);
		return solve(b+d,a);
	}else{
		int k=receive(y);
		if(k==0)return solve(x,O);
		return solve(y,x);
	}
}
/*
void encode(int N, int X) {
	S x;
	x.v.push_back({1,N});
	x.len=N;
	dfs(x,O,X);
}
*/
std::pair<int, int> decode(int N) {
	S x;
	x.v.push_back({1,N});
	x.len=N;
	return solve(x,O);
}
int main(){
	int N;
	cin>>N;
	pii ans=decode(N);
	printf("! %d\n",ans.first);
	fflush(stdout);
	string res;cin>>res;
	if(res==":)")return 0;
	printf("! %d\n",ans.second);
	fflush(stdout);
	cin>>res;
	if(res==":)")return 0;
	return 114514;
}