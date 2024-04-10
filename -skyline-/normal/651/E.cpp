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
//I prefer being hacked than being FST
using namespace std;
int n,m,a[1000005],b[1000005],s,c[1000005];
pair<int,int> srt[1000005];
vector<int> v[1000005];
int q[1000005];
int fnd(int x){return x==c[x]?x:c[x]=fnd(c[x]);};
int clac(int x,int y){
    return (x-1)*m+y;
}
int cty(int x){
    x=fnd(x);
    if(b[x]) return b[x];
    if(v[x].size()==0) return b[x]=1;
    int t=0;
    for(int i=0;i<v[x].size();i++)t=max(t,cty(v[x][i]));
    return b[x]=t+1;
}
int main()
{
    scanf("%d%d",&n,&m);
    s=n*m;
    for(int i=1;i<=s;i++)scanf("%d",a+i);
    for(int i=1;i<=1000002;i++)c[i]=i;
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)srt[j]=mp(a[clac(i,j)],clac(i,j));
            sort(srt+1,srt+m+1);
            int k=0;
            for(int j=1;j<=m;j++){
                    int l=j;
                    while(l<=m&&srt[l+1].first==srt[j].first)l++;
                    q[++k]=fnd(srt[j].second);
                    for(int p=j;p<=l;p++)c[fnd(srt[p].second)]=q[k];
                    j=l;
            }
    }
    
    for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++)srt[j]=mp(a[clac(j,i)],clac(j,i));
            sort(srt+1,srt+n+1);
            int k=0;
            for(int j=1;j<=n;j++){
                    int l=j;
                    while(l<=n&&srt[l+1].first==srt[j].first)l++;
                    q[++k]=fnd(srt[j].second);
                    for(int p=j;p<=l;p++)c[fnd(srt[p].second)]=q[k];
                    j=l;
            }
    }
    
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)srt[j]=mp(a[clac(i,j)],clac(i,j));
            sort(srt+1,srt+m+1);
            int k=0;
            for(int j=1;j<=m;j++){
                    int l=j;
                    while(l<=m&&srt[l+1].first==srt[j].first)l++;
                    q[++k]=fnd(srt[j].second);
                    for(int p=j;p<=l;p++)c[fnd(srt[p].second)]=q[k];
                    j=l;
            }
            for(int p=1;p<k;p++)v[q[p+1]].pb(q[p]);
    }
    
    for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++)srt[j]=mp(a[clac(j,i)],clac(j,i));
            sort(srt+1,srt+n+1);
            int k=0;
            for(int j=1;j<=n;j++){
                    int l=j;
                    while(l<=n&&srt[l+1].first==srt[j].first)l++;
                    q[++k]=fnd(srt[j].second);
                    for(int p=j;p<=l;p++)c[fnd(srt[p].second)]=q[k];
                    j=l;
            }
            for(int p=1;p<k;p++)v[q[p+1]].pb(q[p]);
    }
    for(int i=1;i<=n*m;i++)cty(i);
    for(int i=1;i<=n;i++){
            for(int j=1;j<m;j++)printf("%d ",b[fnd(clac(i,j))]);
            printf("%d\n",b[fnd(clac(i,m))]);
    }             
//	system("pause");
	return 0;
}