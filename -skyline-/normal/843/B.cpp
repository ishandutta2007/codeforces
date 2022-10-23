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
//:
using namespace std;
//
//
int n,s,x,b[50005],a[1005],p[1005],q[1005],ans;
int main()
{
    cin>>n>>s>>x;
    cout<<"? "<<s<<endl;
    fflush(stdout);
    int sx,sy;
    cin>>sx>>sy;
    if(sx>=x){
              cout<<"! "<<sx<<endl;
              fflush(stdout);
              return 0;
    }
    srand(time(0)+20020825);
    ans=orz;
    if(n<=1999){
                for(int i=1;i<=n;i++){
                        if(s==i) continue;
                        cout<<"? "<<i<<endl;
                        fflush(stdout);
                        int o,oo;
                        cin>>o>>oo;
                        if(o>=x)ans=min(ans,o);
                }
                if(ans==orz)ans=-1;
                cout<<"! "<<ans<<endl;
                fflush(stdout);
                return 0;
    }
    ans=1000;
    p[1000]=sx;
    q[1000]=sy;
    for(int i=1;i<=n;i++)b[i]=i;
    random_shuffle(b+1,b+n+1);
    int z=0;
    for(int i=1;i<1000;i++){
            if(b[i+z]==s)z++;
            int o=b[i+z];
            cout<<"? "<<o<<endl;
            fflush(stdout);
            cin>>p[i]>>q[i];
            if(p[i]<=x&&p[i]>p[ans])ans=i;
    }
    int o=p[ans],t=q[ans];
    while(o<x&&t!=-1){
            cout<<"? "<<t<<endl;
            fflush(stdout);
            cin>>o>>t;
    }
    if(o<x){
              cout<<"! -1"<<endl;
              fflush(stdout);
              return 0;
    }
    cout<<"! "<<o<<endl;
    fflush(stdout);
	return 0;
}