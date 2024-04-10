#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define iinf 1000000000
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define lng long long
#define eps 1e-8
#define SQ(a) ((a)*(a))
#define PI 3.14159265359
#define index asdindex



int main(){
#ifdef __ASD__
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

	ios_base::sync_with_stdio(false);

	string s;
	cin>>s;
	int n=s.length();
	vector<int> c(10,0);
	forn(i,n){
		++c[s[i]-'0'];
	}
	sort(all(s));
	reverse(all(s));
	pair<int,pair<string,string> > res(c[0],mp(s,s));
	for(int a=1;a<=9;++a){
		if(!c[a]||!c[10-a])
			continue;
		int r=1;
		vector<int> c1=c,c2=c;
		--c1[a];
		--c2[10-a];
		string r1,r2;
		r1+='0'+a;
		r2+='0'+10-a;
		forn(i,10){
			int t=min(c1[i],c2[9-i]);
			r+=t;
			c1[i]-=t;
			c2[9-i]-=t;
			forn(qqq,t){
				r1+='0'+i;
				r2+='0'+9-i;
			}
		}
		int t=min(c1[0],c2[0]);
		c1[0]-=t;
		c2[0]-=t;
		r+=t;
		forn(p,10){
			forn(q,c1[p]){
				r1+='0'+p;
			}
			forn(q,c2[p]){
				r2+='0'+p;
			}
		}
		reverse(all(r1));
		reverse(all(r2));
		forn(qqq,t){
			r1+='0';
			r2+='0';
		}
		if(r1.length()!=n||r2.length()!=n)
			exit(332);
		res=max(res,mp(r,mp(r1,r2)));
	}
	cout<<res.second.first<<'\n'<<res.second.second;

	return 0;
}