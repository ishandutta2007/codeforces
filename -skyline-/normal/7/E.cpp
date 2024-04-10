//Relive your past life.
//Face your demons.
//The past is never dead,it is not even past.
//The memories are not only the key to the past but...also to the future.
//coded in Rusty Lake
#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n,f[105],I,g[105];
string nam[105];
string s;
vector<int> v;
void get(string w){
    if(w=="") return;
    bool ok=0;
    for(int i=1;i<I;++i)if(w==nam[i])ok=1,v.pb(f[i]),i=I;
    if(!ok)v.pb(3);
}
int solve(){
    v.clear();
    string w="";
    s+=" ";
    for(int i=0;i<s.size();++i){
        if(s[i]==' '){
            get(w);
            w="";
            continue;
        }
        if(s[i]=='+'){
            get(w);
            w="";
            v.pb(-1);
            continue;
        }
        if(s[i]=='-'){
            get(w);
            w="";
            v.pb(-2);
            continue;
        }
        if(s[i]=='/'){
            get(w);
            w="";
            v.pb(-3);
            continue;
        }
        
        if(s[i]=='*'){
            get(w);
            w="";
            v.pb(-4);
            continue;
        }
        if(s[i]=='('){
            get(w);
            w="";
            v.pb(-5);
            continue;
        }
        if(s[i]==')'){
            get(w);
            w="";
            v.pb(-6);
            continue;
        }
        w+=s[i];
    }
    int k=0;
    g[0]=-1;
    for(int i=0;i<v.size();++i){
        if(!v[i]) return 0;
        if(v[i]==-5){
            g[++k]=-1;
            continue;
        }
        if(v[i]==-6){
            g[--k]=3;
            continue;
        }
        if(v[i]==1){
            if(g[k]!=-1) return 0;
            g[k]=1;
            continue;
        }
        if(v[i]==2){
            if(g[k]==-3) return 0;
            g[k]=2;
            continue;
        }
        if(v[i]==3){
            g[k]=3;
            continue;
        }
        if(v[i]==-1||v[i]==-2){
            g[k]=v[i];
            continue;
        }
        if(v[i]==-3||v[i]==-4){
            if(g[k]==1) return 0;
            g[k]=v[i];
            continue;
        }
    }
    k=0;
    int ret=3;
    for(int i=0;i<v.size();++i){
        if(v[i]==-5){
            ++k;
            continue;
        }
        if(v[i]==-6){
            --k;
            continue;
        }
        if(k) continue;
        if(v[i]==1||v[i]==-1||v[i]==-2) return 1;
        if(v[i]==2||v[i]==-3||v[i]==-4) ret=2;
    }
    return ret;
}
int main(){
    f[0]=3;
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        I=i;
        cin>>nam[i];
        if(nam[i]=="#")cin>>nam[i];
        cin>>nam[i];
        getline(cin,s);
        f[i]=solve();
    }
    getline(cin,s);
    I=n+1;
    if(solve())puts("OK");
    else puts("Suspicious");
//	system("pause");
	return 0;
}