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
int n,a2[1002][1002],a5[1002][1002],l;
char s2[1002][1002],s5[1002][1002];
void pt2(int x,int y){
     if(x==1&&y==1) return;
     if(s2[x][y]=='D')pt2(x-1,y);
     else pt2(x,y-1);
     cout<<s2[x][y];
}

void pt5(int x,int y){
     if(x==1&&y==1) return;
     if(s5[x][y]=='D')pt5(x-1,y);
     else pt5(x,y-1);      
     cout<<s5[x][y];
}     
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)a2[i][0]=a5[i][0]=a2[0][i]=a5[0][i]=2147483640;
    a2[0][1]=a5[0][1]=0;
    for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                    int k,x=0,y=0;
                    scanf("%d",&k);
                    if(!k)k=10,l=i;
                    while(k%2==0)k/=2,x++;
                    while(k%5==0)k/=5,y++;
                    if(a2[i-1][j]<a2[i][j-1])s2[i][j]='D',a2[i][j]=a2[i-1][j]+x;
                    else s2[i][j]='R',a2[i][j]=a2[i][j-1]+x;
                    if(a5[i-1][j]<a5[i][j-1])s5[i][j]='D',a5[i][j]=a5[i-1][j]+y;
                    else s5[i][j]='R',a5[i][j]=a5[i][j-1]+y;
            }
    }
    if(a2[n][n]&&a5[n][n]&&l){
                                 cout<<1<<endl;
                                 for(int i=1;i<l;i++)cout<<'D';
                                 for(int i=1;i<n;i++)cout<<'R';
                                 for(int i=l;i<n;i++)cout<<'D';
                                 return 0;
    }
    if(a2[n][n]<a5[n][n])cout<<a2[n][n]<<endl,pt2(n,n);
    else cout<<a5[n][n]<<endl,pt5(n,n);              
	//system("pause");
	return 0;
}