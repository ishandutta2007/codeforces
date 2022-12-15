#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>

#define fi first
#define se second
#define sz(x) ((int)x.size())

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

struct vec{
	lli x,y;
	vec() {}
	vec(lli x,lli y):x(x),y(y) {}
	bool operator<(const vec &rhs)const {
		return x!=rhs.x ? x<rhs.x : y<rhs.y;
	}
	vec operator-(const vec &rhs)const {
		return vec(x-rhs.x,y-rhs.y);
	}
	lli cross(const vec &rhs)const {
		return x*rhs.y-y*rhs.x;
	}
	void print() {
		printf("%lld %lld\n",x,y);
	}
	lli length() const {return x*x+y*y;}
};
vector<vec> a,b;
int n,m;

vector<pll> as,bs;
vector<int> pi;

vector<vec> get_convex(vector<vec> &arr) {
	sort(arr.begin(),arr.end());
	sort(arr.begin()+1,arr.end(), [&](const vec &a,const vec &b) {
		vec av=a-arr[0], bv=b-arr[0];
		if(av.cross(bv)==0) return av.length() < bv.length();
		else return av.cross(bv)>0;
	});

	vector<vec> res;
	for(int i=0;i<sz(arr);i++) {
		while(sz(res)>=2) {
			int s=sz(res);
			vec lv=res[s-2]-res[s-1], rv=arr[i]-res[s-1];
			if(rv.cross(lv)>0) break;
			res.pop_back();
		}
		res.push_back(arr[i]);
	}
	return res;
}
void getpi(){
	pi.resize(sz(as),0);
	int j=0;
	for(int i=1;i<sz(as);i++) {
		while(j && as[i]!=as[j]) j=pi[j-1];
		if(as[i]==as[j]) pi[i]=++j;
	}
}
bool kmp() {
	int j=0;
	for(int i=0;i<sz(bs);i++) {
		while(j && as[j]!=bs[i]) j=pi[j-1];
		if(as[j]==bs[i]) {
			j++;
			if(j==sz(as)) return true;
		}
	}
	return false;
}
int main() {
	lli x,y;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) {
		scanf("%lld%lld",&x,&y);
		a.push_back(vec(x,y));
	}
	for(int i=0;i<m;i++) {
		scanf("%lld%lld",&x,&y);
		b.push_back(vec(x,y));
	}

	a=get_convex(a);
	b=get_convex(b);

	if(sz(a)!=sz(b)) {
		puts("No");
		return 0;
	}
	if(sz(a)==2) {
		if((a[1]-a[0]).length()==(b[1]-b[0]).length())
			puts("Yes");
		else
			puts("No");
		return 0;
	}

	for(int i=0;i<sz(a);i++) 
		as.push_back(pll((a[(i+2)%sz(a)]-a[(i+1)%sz(a)]).cross(a[(i+1)%sz(a)]-a[i]),(a[(i+1)%sz(a)]-a[i]).length()));

	for(int i=0;i<sz(b);i++) 
		bs.push_back(pll((b[(i+2)%sz(b)]-b[(i+1)%sz(b)]).cross(b[(i+1)%sz(b)]-b[i]),(b[(i+1)%sz(b)]-b[i]).length()));

	for(int i=0;i<sz(b);i++)
		bs.push_back(bs[i]);

	getpi();

	if(kmp()) 
		puts("Yes");
	else
		puts("No");

	return 0;
}