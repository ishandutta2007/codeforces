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
char c[1005][1005];
bool b[5][5];
int n,m,a[4][1000005],ans=2147483640;
vector<int> v[1000010];
int main()
{
    scanf("%d%d",&n,&m);
    memset(a,-1,sizeof(a));
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)scanf(" %c",c[i]+j);
    }
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                    if(c[i][j]>'0'&&c[i][j]<'4'&&c[i-1][j]>'0'&&c[i-1][j]<'4')b[c[i][j]-'0'][c[i-1][j]-'0']=b[c[i-1][j]-'0'][c[i][j]-'0']=1;
                    if(c[i][j]>'0'&&c[i][j]<'4'&&c[i][j-1]>'0'&&c[i][j-1]<'4')b[c[i][j]-'0'][c[i][j-1]-'0']=b[c[i][j-1]-'0'][c[i][j]-'0']=1;

            if(c[i][j]!='.') continue;
            int k=i*m-m+j;
            if(c[i-1][j]=='.')v[k].push_back(k-m);
            else if(c[i-1][j]=='1')v[1000001].push_back(k),v[k].push_back(1000001);
            else if(c[i-1][j]=='2')v[1000002].push_back(k),v[k].push_back(1000002);
            else if(c[i-1][j]=='3')v[1000003].push_back(k),v[k].push_back(1000003);
            if(c[i+1][j]=='.')v[k].push_back(k+m);
            else if(c[i+1][j]=='1')v[1000001].push_back(k),v[k].push_back(1000001);
            else if(c[i+1][j]=='2')v[1000002].push_back(k),v[k].push_back(1000002);
            else if(c[i+1][j]=='3')v[1000003].push_back(k),v[k].push_back(1000003);
            if(c[i][j-1]=='.')v[k].push_back(k-1);
            else if(c[i][j-1]=='1')v[1000001].push_back(k),v[k].push_back(1000001);
            else if(c[i][j-1]=='2')v[1000002].push_back(k),v[k].push_back(1000002);
            else if(c[i][j-1]=='3')v[1000003].push_back(k),v[k].push_back(1000003);
            if(c[i][j+1]=='.')v[k].push_back(k+1);
            else if(c[i][j+1]=='1')v[1000001].push_back(k),v[k].push_back(1000001);
            else if(c[i][j+1]=='2')v[1000002].push_back(k),v[k].push_back(1000002);
            else if(c[i][j+1]=='3')v[1000003].push_back(k),v[k].push_back(1000003);
            }
    }
    for(int i=1;i<=3;i++){
            queue<int> q;
            q.push(1000000+i);
            a[i][i+1000000]=0;
            while(!q.empty()){
                              int k=q.front();
                              q.pop();
                              if(k>1000000){
                                            for(int j=1000001;j<=1000003;j++){
                                                    if(b[j-1000000][k-1000000]&&a[i][j]==-1)q.push(j),a[i][j]=a[i][k];
                                            }
                              }
                              for(int j=0;j<v[k].size();j++)if(a[i][v[k][j]]==-1)q.push(v[k][j]),a[i][v[k][j]]=a[i][k]+1;
            }
    }
    for(int i=1;i<=1000000;i++){
            if(a[1][i]!=-1&&a[2][i]!=-1&&a[3][i]!=-1)ans=min(a[1][i]+a[2][i]+a[3][i]-2,ans);
    }
    for(int i=1000001;i<=1000003;i++){
            if(a[1][i]!=-1&&a[2][i]!=-1&&a[3][i]!=-1)ans=min(max(0,a[1][i]-1)+max(0,a[2][i]-1)+max(0,a[3][i]-1),ans);
    }
    if(ans==2147483640)ans=-1;
    printf("%d\n",ans);
//	system("pause");
	return 0;
}