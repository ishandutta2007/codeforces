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
//from CrAzYUnIoN
//I prefer being hacked to being FST
using namespace std;
//
bool f[305][305][8][155];
int n,b[305][305],t[155],s;
int x[8]={0,1,1,1,0,-1,-1,-1},y[8]={1,1,0,-1,-1,-1,0,1};
void cty(int p,int q,int r,int o){
     if(f[p][q][r][o]) return;
     f[p][q][r][o]=b[p][q]=1;
     if(o>s) return;
     if(!t[o])cty(p+x[r],q+y[r],r,o+1);
     else{
          p+=x[r],q+=y[r];
          r--;
          if(r==-1)r=7;
          cty(p,q,r,o+1);
          r+=2;
          if(r>7)r-=8;
          cty(p,q,r,o+1);
     }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
            int k;
            scanf("%d",&k);
            s+=k;
            t[s]=1;
    }
    if(!t[1])cty(150,150,0,2);
    else cty(150,150,1,2),cty(150,150,7,2);
    int ans=0;
    for(int i=0;i<=300;i++){
            for(int j=0;j<=300;j++)ans+=b[i][j];
    }
    printf("%d\n",ans);
	//system("pause");
	return 0;
}