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
int T,n,cnt[205];
char s[55],t[55];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i)scanf(" %c",s+i);
        for(int i=1;i<=n;++i)scanf(" %c",t+i);
        for(int i=97;i<=122;++i)cnt[i]=0;
        bool ok=1;
        for(int i=1;i<=n;++i)++cnt[s[i]],++cnt[t[i]];
        for(int i=97;i<=122;++i)if(cnt[i]&1)ok=0;
        if(ok)printf("Yes\n");
        else{
            printf("No\n");
            continue;
        }
        vector<pair<int,int> >v;
        for(int i=1;i<n;++i){
            if(s[i]==t[i]) continue;
            bool ok=0;
            for(int j=i+1;j<=n;++j){
                if(s[i]==s[j]){
                    ok=1;
                    v.pb(mp(j,i));
                    swap(s[j],t[i]);
                    break;
                }
            }
            if(ok) continue;
            for(int j=i+1;j<=n;++j){
                if(s[i]==t[j]){
                    v.pb(mp(n,j));
                    swap(s[n],t[j]);
                    v.pb(mp(n,i));
                    swap(s[n],t[i]);
                    break;
                }
            }
        }
        printf("%d\n",v.size());
        for(int i=0;i<v.size();++i)printf("%d %d\n",v[i].first,v[i].second);
    }
   // system("pause");
    return 0;
}