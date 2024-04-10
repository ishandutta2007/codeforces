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
vector<int> v1[205],v2[205];
bitset<65566> b[201];
int n,m;
bitset<65566> res;
vector<int> v;
void cty(){
     for(int i=0;i<=65560;i++)res[i]=0;
     int a=1,s=0;
     for(int i=1;i<=15;i++){
             if(v.size()<i) return;
             int o=0;
             for(int j=0;j<i-1;j++)o=o*2+v[j];
             for(int j=i-1;j<v.size();j++){
                     o=o*2+v[j];
                     o&=a;
                     res[o+s]=1;
             }
             a=a*2+1;
             s=s*2+2;
     }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
            char c;
            scanf(" %c",&c);
            v.clear();
            while(c!='\n'){
                           v.pb(c-48);
                           c=getchar();
            }
            cty();
            b[i]=res;
            if(v.size()<15)v1[i]=v2[i]=v;
            else{
                 for(int j=0;j<15;j++)v1[i].pb(v[j]),v2[i].pb(v[v.size()-15+j]);
            }
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            b[n+i]=b[x]|b[y];
            v=v2[x];
            for(int j=0;j<v1[y].size();j++)v.pb(v1[y][j]);
            cty();
            b[n+i]|=res;
            if(v1[x].size()==15)v1[n+i]=v1[x];
            else if(v1[x].size()+v1[y].size()>=15){
                 v1[n+i]=v1[x];
                 for(int j=0;j<15-v1[x].size();j++)v1[n+i].pb(v1[y][j]);
            }
            else{
                 v1[n+i]=v1[x];
                 for(int j=0;j<v1[y].size();j++)v1[n+i].pb(v1[y][j]);
            }
            if(v2[y].size()==15)v2[n+i]=v2[y];
            else if(v2[y].size()+v2[x].size()>=15){
                 for(int j=v2[y].size()+v2[x].size()-15;j<v2[x].size();j++)v2[n+i].pb(v2[x][j]);
                 for(int j=0;j<v2[y].size();j++)v2[n+i].pb(v2[y][j]);
            }
            else{
                 v2[n+i]=v1[x];
                 for(int j=0;j<v2[y].size();j++)v2[n+i].pb(v2[y][j]);
            }
            int k=0;
            while(b[n+i][k])k++;
            int ans=0,o=2;
            while(k>=o){
                        k-=o;
                        ans++;
                        o*=2;
            }
            printf("%d\n",ans);
    }
//	system("pause");
	return 0;
}