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
int n,m,k,a[2][505][505],ans;
char s[505][505];
int mod(int o){
    if(o>=1000000007)o-=1000000007;
    return o;
}
int main()
{
    scanf("%d%d",&n,&m);
    k=(n+m+2)/2;
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    if(s[1][1]!=s[n][m]){
                         printf("0\n");
                         return 0;
    }
    a[1][1][n]=1;
    for(int l=2;l<k;l++){
            for(int i=max(1,l-m);i<=n;i++){
                    if(i>=l) break;
                    int j=l-i;
                    for(int r=min(m+n-l+1,n);r>=i;r--){
                            int c=m+n+2-l-r;
                            if(c>m) break;
                            int q=a[(l&1)^1][i][r];
                            if(i<n&&r>1&&s[i+1][j]==s[r-1][c])a[l&1][i+1][r-1]=mod(a[l&1][i+1][r-1]+q); 
                            if(i<n&&c>1&&s[i+1][j]==s[r][c-1])a[l&1][i+1][r]=mod(a[l&1][i+1][r]+q);
                            if(j<m&&r>1&&s[i][j+1]==s[r-1][c])a[l&1][i][r-1]=mod(a[l&1][i][r-1]+q);
                            if(j<m&&c>1&&s[i][j+1]==s[r][c-1])a[l&1][i][r]=mod(a[l&1][i][r]+q);
                    }
            }
            memset(a[(l&1)^1],0,sizeof(a[(l&1)^1]));
    }
    if(!((n+m)&1)){
                for(int i=max(1,k-m);i<=n;i++) {
                        if(k<=i) break;
                        int j=k-i;
                        ans=mod(ans+a[(k&1)^1][i][i]);
                }
    }
    else{
         for(int i=max(1,k-m);i<=n;i++) {
                 if(k<=i) break;
                 int j=k-i;
                 ans=mod(ans+mod(a[(k&1)^1][i][i]+a[(k&1)^1][i][i+1]));
         }
    }
    printf("%d\n",ans);
	//system("pause");
	return 0;
}