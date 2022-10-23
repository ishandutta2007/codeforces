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
#define X    first
#define Y    second
//:
using namespace std;
//
//
int n,q;
int a[50005];
int x[100005],y[100005];
vector<pair<int,int> > v[1000005];
bool u[100005];
vector<int> o;
vector<int> p[1005];
int t[100005],ans[100005];
int f[1000005];
int main()
{
    char c=getchar();
    while(c!='\n')a[++n]=c-'a'+1,c=getchar();
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
            int t[5]={},s=0;
            c=getchar();
            while(c=='\n')c=getchar();
            while(c!=' ')t[++s]=c-'a'+1,c=getchar();
            if(s==1)x[i]=t[1];
            else if(s==2)x[i]=t[1]*30+t[2];
            else if(s==3)x[i]=t[1]*900+t[2]*30+t[3];
            else x[i]=t[1]*27000+t[2]*900+t[3]*30+t[4];
            s=0;  
            c=getchar(); 
            while(c!='\n')t[++s]=c-'a'+1,c=getchar();
            if(s==1)y[i]=t[1];
            else if(s==2)y[i]=t[1]*30+t[2];
            else if(s==3)y[i]=t[1]*900+t[2]*30+t[3];
            else y[i]=t[1]*27000+t[2]*900+t[3]*30+t[4];
    }
    for(int i=1;i<=n;i++)v[a[i]].pb(mp(i,i));
    for(int i=1;i<=n-1;i++)v[a[i]*30+a[i+1]].pb(mp(i,i+1));
    for(int i=1;i<=n-2;i++)v[a[i]*900+a[i+1]*30+a[i+2]].pb(mp(i,i+2));
    for(int i=1;i<=n-3;i++)v[a[i]*27000+a[i+1]*900+a[i+2]*30+a[i+3]].pb(mp(i,i+3));
    for(int i=1;i<=1000000;i++)if(v[i].size()>1000)o.pb(i);
    memset(t,-1,sizeof(t));
    for(int i=0;i<o.size();i++){
            for(int j=1;j<=q;j++)if(t[j]==-1&&(x[j]==o[i]||y[j]==o[i])&&(v[x[i]].size()&&v[y[i]].size()))t[j]=i,p[i].pb(j);
    }
    for(int i=1;i<=q;i++){
            if(t[i]!=-1) continue;
            int l=0;
            ans[i]=orz;
            if(v[x[i]].size()==0||v[y[i]].size()==0) continue;
            for(int j=0;j<v[x[i]].size();j++){
                    while(l<v[y[i]].size()-1&&v[y[i]][l+1].X<=v[x[i]][j].X)l++;
                    ans[i]=min(ans[i],max(v[x[i]][j].Y,v[y[i]][l].Y)-min(v[x[i]][j].X,v[y[i]][l].X));
                    if(l<v[y[i]].size()-1)ans[i]=min(ans[i],max(v[x[i]][j].Y,v[y[i]][l+1].Y)-min(v[x[i]][j].X,v[y[i]][l+1].X));
            }
    }
    for(int i=0;i<o.size();i++){
            if(!p[i].size()) continue;
            for(int j=1;j<=1000000;j++)f[j]=orz;
            v[o[i]].pb(mp(orz,orz+orz));
            int l=0;
            for(int j=1;j<=n;j++){
                    int z=a[j];
                    while(v[o[i]][l+1].X<=j)l++;
                    f[z]=min(f[z],max(v[o[i]][l].Y,j)-min(v[o[i]][l].X,j));
                    f[z]=min(f[z],max(v[o[i]][l+1].Y,j)-min(v[o[i]][l+1].X,j));
            }
            l=0;
            for(int j=1;j<=n-1;j++){
                    int z=a[j]*30+a[j+1];
                    while(v[o[i]][l+1].X<=j)l++;
                    f[z]=min(f[z],max(v[o[i]][l].Y,j+1)-min(v[o[i]][l].X,j));
                    f[z]=min(f[z],max(v[o[i]][l+1].Y,j+1)-min(v[o[i]][l+1].X,j));
            }
            l=0;  
            for(int j=1;j<=n-2;j++){
                    int z=a[j]*900+a[j+1]*30+a[j+2];
                    while(v[o[i]][l+1].X<=j)l++;
                    f[z]=min(f[z],max(v[o[i]][l].Y,j+2)-min(v[o[i]][l].X,j));
                    f[z]=min(f[z],max(v[o[i]][l+1].Y,j+2)-min(v[o[i]][l+1].X,j));
            }
            l=0;
            for(int j=1;j<=n-3;j++){
                    int z=a[j]*27000+a[j+1]*900+a[j+2]*30+a[j+3];
                    while(v[o[i]][l+1].X<=j)l++;
                    f[z]=min(f[z],max(v[o[i]][l].Y,j+3)-min(v[o[i]][l].X,j));
                    f[z]=min(f[z],max(v[o[i]][l+1].Y,j+3)-min(v[o[i]][l+1].X,j));
            }
            v[o[i]].pop_back();
            for(int j=0;j<p[i].size();j++)ans[p[i][j]]=(o[i]==x[p[i][j]]?f[y[p[i][j]]]:f[x[p[i][j]]]);
    }
    for(int i=1;i<=q;i++)printf("%d\n",ans[i]==orz?-1:ans[i]+1);
	//system("pause");
	return 0;
}