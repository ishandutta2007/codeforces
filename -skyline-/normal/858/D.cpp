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
#include<unordered_map>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
//:
using namespace std;
//
//
unordered_map<int,int> m[10];
int n;
vector<int> v[70005][10];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            for(int j=9;j;j--){
                    int t=1;
                    for(int k=1;k<=j;k++){
                            t*=10;
                            v[i][k].pb(x%t);
                            int o=m[k][x%t];
                            if(o==0)m[k][x%t]=i;
                            else if(o!=-1&&o!=i)m[k][x%t]=-1;
                    }
                    x/=10;
            }
    }
    for(int i=1;i<=n;i++){
            int x=0,k=0;
            for(int j=1;j<=9;j++){
                    for(int l=0;l<v[i][j].size();l++){
                            if(m[j][v[i][j][l]]==i){
                                                    x=v[i][j][l];
                                                    k=j;
                                                    j=10;
                                                    break;
                            }
                    }
            }
            if(k==1)printf("%01d\n",x);
            if(k==2)printf("%02d\n",x);
            if(k==3)printf("%03d\n",x);
            if(k==4)printf("%04d\n",x);
            if(k==5)printf("%05d\n",x);
            if(k==6)printf("%06d\n",x);
            if(k==7)printf("%07d\n",x);
            if(k==8)printf("%08d\n",x);
            if(k==9)printf("%09d\n",x);
    }
//	system("pause");
	return 0;
}