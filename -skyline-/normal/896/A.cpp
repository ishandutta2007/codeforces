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
#define orz  1000000007ll
//:
using namespace std;
ll f[100005];
string s=" What are you doing at the end of the world? Are you busy? Will you save us?";
string s2=" What are you doing while sending ";
string s3="  ? Are you busy? Will you send ";
string s4="  ?";
int main()
{
    f[0]=75;
    s2+='"';
    s3[1]='"';
    s3+='"';
    s4[1]='"';
    for(int i=1;i<=100000;i++){
            f[i]=f[i-1]*2+68;
            if(f[i]>orz*orz)f[i]=orz*orz;
    }
    int q,n;
    ll k;
    scanf("%d",&q);
    while(q--){
               scanf("%d%I64d",&n,&k);
               if(k>f[n]){
                          putchar('.');
                          continue;
               }
               bool ok=0;
               for(int i=n;i;i--){
                       if(k<=34){
                                 ok=1;
                                 putchar(s2[k]);
                                 break;
                       }
                       k-=34;
                       if(k<=f[i-1]) continue;
                       k-=f[i-1];
                       if(k<=32){
                                 ok=1;
                                 putchar(s3[k]);
                                 break;
                       }
                       k-=32;
                       if(k<=f[i-1]) continue;
                       k-=f[i-1];
                       if(k<=2){
                                ok=1;
                                putchar(s4[k]);
                                break;
                       }
               }
               if(!ok)putchar(s[k]);
    }
	//system("pause");
	return 0;
}