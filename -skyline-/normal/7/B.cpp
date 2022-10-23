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
int t,m,a[105],cnt;
int main(){
    ios::sync_with_stdio(0);
    cin>>t>>m;
    for(int _=1;_<=t;++_){
        string s;
        cin>>s;
        if(s=="alloc"){
            int n;
            cin>>n;
            int l=1;
            bool ok=0;
            for(int i=1;i<=m;++i){
                if(a[i])l=i+1;
                else if(i-l+1>=n){
                    ++cnt;
                    for(int j=l;j<=i;++j)a[j]=cnt;
                    ok=1;
                    break;
                }
            }
            if(ok)cout<<cnt<<endl;
            else cout<<"NULL"<<endl;
            continue;
        }
        if(s=="erase"){
            int n;
            cin>>n;
            if(n<1||n>cnt){
                cout<<"ILLEGAL_ERASE_ARGUMENT"<<endl;
                continue;
            }
            bool ok=0;
            for(int i=1;i<=m;++i)if(a[i]==n)a[i]=0,ok=1;
            if(!ok)cout<<"ILLEGAL_ERASE_ARGUMENT"<<endl;
            continue;
        }
        for(int i=m-1;i;--i){
            if(a[i]) continue;
            for(int j=i;j<=m;++j)a[j]=a[j+1];
        }
    }
	//system("pause");
	return 0;
}