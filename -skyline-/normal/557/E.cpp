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
bool b[5005][5005];
int n,k,a[5005],sa[25000005],sb[25000005],s[25000005],v[25000005],q=1,ccs;
char cc[5005];
int dfs(int x){
    v[x]=s[x];
    if(sa[x]!=-1)s[x]+=dfs(sa[x]);
    if(sb[x]!=-1)s[x]+=dfs(sb[x]);
    return s[x];
}
void ope(int x,int k){
     if(k<=v[x]) return;
     k-=v[x];
     if(sa[x]!=-1){
                   if(s[sa[x]]>=k)cc[++ccs]='a',ope(sa[x],k);
                   else cc[++ccs]='b',ope(sb[x],k-s[sa[x]]);
     }
     else cc[++ccs]='b',ope(sb[x],k);
}   
int main()                                              
{
    char c=' ';
    while(c!='a'&&c!='b')c=getchar();
    while(c=='a'||c=='b')a[++n]=c-96,c=getchar();
    scanf("%d",&k);
    for(int i=1;i<=n;i++)b[i][i]=1;
    for(int i=1;i<n;i++)b[i][i+1]=(a[i]==a[i+1]);
    for(int i=1;i<n-1;i++)b[i][i+2]=(a[i]==a[i+2]);
    for(int i=1;i<n-2;i++)b[i][i+3]=(a[i]==a[i+3]);
    for(int j=4;j<n;j++){
            for(int i=1;i+j<=n;i++)b[i][i+j]=(a[i]==a[i+j]&&b[i+2][i+j-2]);
    }
    memset(sa,-1,sizeof(sa));
    memset(sb,-1,sizeof(sb));
    for(int i=1;i<=n;i++){
            int o=1;
            for(int j=i;j<=n;j++){
                    if(a[j]==1){
                                if(sa[o]==-1)sa[o]=++q;
                    }
                    else if(sb[o]==-1)sb[o]=++q;
                    o=((a[j]==1)?sa[o]:sb[o]);
                    if(b[i][j])s[o]++;
            }
    }                                                
    dfs(1);
    ope(1,k);
    for(int i=1;i<=ccs;i++)printf("%c",cc[i]);
    printf("\n");                
	//system("pause");
	return 0;
}