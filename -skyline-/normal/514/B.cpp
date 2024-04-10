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
//:
using namespace std;
int n,x,y,a[2000],b[2000],r,c;
bitset<2000> f;
int main()
{
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i];
            if(a[i]==x) r=1,f.set(i);
            if(b[i]==y) c=1,f.set(i);
    }
    int k=1,ans=r+c;
    while(f.count()!=n){
                        ans++;
                        while(f[k])k++;
                        f.set(k);
                        int xx=x-a[k],yy=y-b[k],mm=0;
                        if(xx<0)xx=-xx,mm++;
                        if(yy<0)yy=-yy,mm++;
                        int gg=__gcd(xx,yy);
                        xx/=gg,yy/=gg;
                        mm%=2;
                        for(int i=k+1;i<=n;i++){
                                int xxx=x-a[i],yyy=y-b[i],mmm=0;
                                if(xxx<0)xxx=-xxx,mmm++;
                                if(yyy<0)yyy=-yyy,mmm++;
                                int ggg=__gcd(xxx,yyy);
                                xxx/=ggg,yyy/=ggg;
                                if(xxx==xx&&yyy==yy&&(mmm%2)==mm)f.set(i);
                        }
    }
    cout<<ans<<endl;                    
                                     
  //  system("pause");
    return 0;
}