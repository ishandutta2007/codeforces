#pragma comment(linker,"/STACK:256000000")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <iomanip>
#include <sstream>
#include <stack>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define iinf 1000000000
#define linf 1000000000000000000LL
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define lng long long
#define eps 1e-10
#define EQ(a,b) (fabs((a)-(b))<eps)
#define SQ(a) ((a)*(a))
#define PI 3.14159265359
#define index asdindex
#define FI first
#define SE second
#define prev asdprev
#define PII pair<int,int> 
#define X first
#define Y second
#define unlink asdunlink
typedef unsigned char uchar;
typedef unsigned int uint;

map<string,int> tags;
int src[600000];
int sz;
char line[1100000];
int res[210];
int st[210];

void gentest(){
	fclose(stdin);
	freopen("input.txt","w",stdout);

	stack<string> st;
	int lim=1000000;
	int cl=0;
	int l=0;
	while(cl||l+4<=lim){
		int tr=rand()%3;
		string s;
		s+='a'+rand()%2;
		if(tr==0){
			if(l+cl+7>lim)
				continue;
			st.push(s);
			l+=3;
			cl+=4;
			cout<<'<'<<s<<'>';
		}else if(tr==1){
			if(l+cl+4>lim)
				continue;
			l+=4;
			cout<<'<'<<s<<"/>";
		}else{
			if(st.empty())
				continue;
			s=st.top();
			st.pop();
			l+=4;
			cl-=4;
			cout<<"</"<<s<<'>';
		}
	}
	cout<<endl;
	int m=200;
	cout<<m<<endl;
	forn(qq,m){
		int l=200;
		forn(i,l){
			cout<<(char)('a'+rand()%2)<<' ';
		}
		cout<<'\n';
	}
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);

	//gentest();return 0;

	gets_s(line);
	for(int i=0;line[i];){
		if(line[i]!='<')
			exit(123);
		++i;
		int i0=i;
		while(line[i]!='>')
			++i;
		if(line[i0]=='/'){
			src[sz++]=-1;
		}else{
			bool cl=line[i-1]=='/';
			if(cl)
				line[i-1]=0;
			line[i]=0;
			string s=line+i0;
			if(!tags.count(s)){
				int t=tags.size();
				tags[s]=t;
			}
			src[sz++]=tags[s];
			if(cl)
				src[sz++]=-1;
		}
		++i;
	}
	int m;
	cin>>m;
	gets(line);

	forn(qq,m){
		gets(line);
		stringstream ss(line);
		vector<int> v;
		string s;
		while(ss>>s){
			int c;
			if(tags.count(s))
				c=tags[s];
			else
				c=-1;
			v.pb(c);
		}
		
		int stl=0;
		int l=v.size();
		int r=0;
		int d=0;

		forn(i,sz){
			if(src[i]==-1){
				if(stl&&d==st[stl-1])
					--stl;
				--d;
			}else{
				++d;
				if(src[i]==v[stl]){
					if(stl+1==l)
						++r;
					else
						st[stl++]=d;
				}
			}
		}

		cout<<r<<'\n';
	}

    return 0;
}