#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)		(a).begin(),(a).end()
#define sz(a)		int((a).size())
#define FOR(i,a,b)	for(int i=a;i<b;++i)
#define REP(i,n)	FOR(i,0,n)
#define UN(v)		sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)		memset(a,b,sizeof a)
#define pb			push_back
#define X			first
#define Y			second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

bool e(char c){ return isalpha(c) || isdigit(c); }

struct QWEQWE{ 
	map<string,string> D;
	string expr;
	vector<string> t;
	void tokenize(const string&s){
		for(int i=0;i<s.size();){
			if(e(s[i])){
				string c;
				for(;e(s[i]);c+=s[i++]);
				if(D.count(c))tokenize(D[c]);
				else t.push_back(c);
			}else t.push_back(string(1,s[i++]));
		}
	}
	int i;
	void parse0(){
		
	}
	string polsky(){
		tokenize(expr);
		i=0;
		parse0();
		return "";
	}
	map<string,int> F,G;
	int f(const string&s){
		if(F.count(s)) return F[s];
		int &res=F[s];
		if(D.count(s)){
			res=f(D[s]);
			return res;
		}
		res=0;
		vector<string> t;
		for(int i=0;i<s.size();){
			if(e(s[i])){
				string c;
				for(;e(s[i]);c+=s[i++]);
				t.push_back(c);
			}else t.push_back(string(1,s[i++]));
		}
		int k=0;
		REP(i,sz(t)){
			if(t[i]=="(")++k;
			else if(t[i]==")")--k;
			else if(k==0 && (t[i]=="+" || t[i]=="-")){
				res=1;
				break;
			}
		}
		return res;
	}
	map<string,int> T;
	int term(const string&s){
		if(T.count(s)) return T[s];
		int &res=T[s];
		if(D.count(s)){
			res=term(D[s]);
			return res;
		}
		res=1;
		REP(i,sz(s))if(!e(s[i]))res=0;
		if(res) return res;
		res=1-res;
		if(s[0]!='(') res=0;
		int k=1;
		for(int i=1;i+1<sz(s);++i){
			if(s[i]=='(')++k;
			else if(s[i]==')')--k;
			if(k==0)res=0;
		}
		if(s[sz(s)-1]!=')')res=0;
		return res;
	}
	int g(const string&s){
		if(G.count(s)) return G[s];
		int &res=G[s];
		if(D.count(s)){
			res=g(D[s]);
			return res;
		}
		res=1;
		vector<string> t;
		for(int i=0;i<s.size();){
			if(e(s[i])){
				string c;
				for(;e(s[i]);c+=s[i++]);
				t.push_back(c);
			}else t.push_back(string(1,s[i++]));
		}
		for(int i=1;i+1<sz(t);++i)if(t[i]=="*" || t[i]=="/"){
			string A[]={t[i-1],t[i+1]};
			REP(k,2){
				string w=A[k];
				if(isalpha(w[0]) && D.count(w)){
					if(f(D[w])) { res=0; break; }
				}
			}
		}
		REP(i,sz(t)-1)if(t[i]=="-"){
			string w=t[i+1];
			if(isalpha(w[0]) && D.count(w)){
				if(f(D[w])) { res=0; break; }
			}
		}else if(t[i]=="/"){
			string w=t[i+1];
			if(isalpha(w[0]) && D.count(w)){
				if(!term(D[w])) { res=0; break; }
			}
		}
		if(res) REP(i,sz(t))if(isalpha(t[i][0])){
			if(D.count(t[i]) && !g(D[t[i]])){
				res=0;
				break;
			}
		}
		return res;
	}
	bool check(){
		return g(expr);
	}
}P;

int n;
char s[256];

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	n=atoi(gets(s));
	REP(i,n){
		gets(s);
		string d = "define";
		char*i=s;
		for(;*i;++i){
			char z = 0; bool ok=false;
			swap(i[sz(d)],z);
			if(i==d) ok=true;
			swap(i[sz(d)],z);
			if(ok){ i+=sz(d); break; }
		}
		string A,B;
		for(;!isalpha(*i);++i);
		for(;isalpha(*i);A+=*i++);
		for(;*i;++i)if(!isspace(*i))B+=*i;
		P.D[A]=B;
		//Q.D[A]="("+B+")";
	}
	gets(s);
	string B;
	for(char*i=s;*i;++i)if(!isspace(*i))B+=*i;
	P.expr=B;
	//Q.expr=B;
	puts(P.check()?"OK":"Suspicious");
	return 0;
}