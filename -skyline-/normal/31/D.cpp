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
//:
using namespace std;
int w,h,n,res;
bool a[105][105][5],u[105][105];
vector<int> v;
void ope(int x,int y){
     res++,u[x][y]=1;
     if(!(u[x][y-1]||a[x][y][1])) ope(x,y-1);
     if(!(u[x-1][y]||a[x][y][2])) ope(x-1,y);
     if(!(u[x][y+1]||a[x][y][3])) ope(x,y+1);
     if(!(u[x+1][y]||a[x][y][4])) ope(x+1,y);
}
     
int main()
{
    scanf("%d%d%d",&w,&h,&n);
    for(int i=1;i<=n;i++){
            int s,d,f,g;
            scanf("%d%d%d%d",&s,&d,&f,&g);
            if(s==f) for(int j=d;j<g;j++)a[s][j+1][4]=a[s+1][j+1][2]=1;
            else for(int j=s;j<f;j++)a[j+1][d][3]=a[j+1][d+1][1]=1;
    }
    for(int i=1;i<=h;i++)a[1][i][2]=a[w][i][4]=1;
    for(int i=1;i<=w;i++)a[i][1][1]=a[i][h][3]=1;
    for(int i=1;i<=w;i++){
            for(int j=1;j<=h;j++)if(!u[i][j])res=0,ope(i,j),v.push_back(res);
    }
    sort(v.begin(),v.end()); 
    for(int i=0;i<v.size()-1;i++)printf("%d ",v[i]);
    printf("%d\n",v[v.size()-1]);                
	//system("pause");
	return 0;
}