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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//:
using namespace std;
int n,ans;
char c;
string s;
bool ok[200],o2[200];
int cnt;
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    cnt=26;
    for(int i='a';i<='z';i++)ok[i]=1;
    for(int i=1;i<=n;i++){
        cin>>c>>s;
        if(c=='!'){
            if(cnt==1)ans++;
            else{
                for(int i='a';i<='z';i++)o2[i]=0;
                for(int i=0;i<s.size();i++)o2[s[i]]=1;
                for(int i='a';i<='z';i++)if(!o2[i]&&ok[i])ok[i]=0,cnt--;
            }
        }
        if(c=='.'){
            if(cnt>1){
                for(int i=0;i<s.size();i++)if(ok[s[i]])ok[s[i]]=0,cnt--;
            }
        }
        if(c=='?'&&cnt==1)ans++;
        if(c=='?'&&i<n){
            if(ok[s[0]])ok[s[0]]=0,cnt--;
        }
    }
    if(ok[s[0]]&&ans)ans--;
    cout<<ans<<endl;
	//system("pause");
	return 0;
}