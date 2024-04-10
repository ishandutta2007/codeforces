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
using namespace std;
int n,t[1000005],ch[1000005][2],ans[1000005],r,f[1000005],out[1000005];
void ope(int x){
    if(!t[x]) return;
    if(t[x]<4)ope(ch[x][0]),ope(ch[x][1]);
    else ope(ch[x][0]);
    if(t[x]==1)ans[x]=ans[ch[x][0]]&ans[ch[x][1]];
    else if(t[x]==2)ans[x]=ans[ch[x][0]]|ans[ch[x][1]];
    else if(t[x]==3)ans[x]=ans[ch[x][0]]^ans[ch[x][1]];
    else ans[x]=!ans[ch[x][0]];
}
void dfs(int x,int k){
    if(!t[x]){
        if((ans[x]==1&&k%2==0)||(ans[x]==0&&k<2))out[x]=0;
        else out[x]=1;
        return;
    }
    int p=k&1,q=k>>1;
    if(t[x]==4)dfs(ch[x][0],p*2+q);
    else if(t[x]==1){
        if(ans[ch[x][1]])dfs(ch[x][0],k);
        else dfs(ch[x][0],p*3);
        if(ans[ch[x][0]])dfs(ch[x][1],k);
        else dfs(ch[x][1],p*3);
    }
    else if(t[x]==2){
        if(!ans[ch[x][1]])dfs(ch[x][0],k);
        else dfs(ch[x][0],q*3);
        if(!ans[ch[x][0]])dfs(ch[x][1],k);
        else dfs(ch[x][1],q*3);
    }
    else{
        if(!ans[ch[x][1]])dfs(ch[x][0],k);
        else dfs(ch[x][0],p*2+q);
        if(!ans[ch[x][0]])dfs(ch[x][1],k);
        else dfs(ch[x][1],p*2+q);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        string s;
        cin>>s;
        if(s=="AND")t[i]=1;
        else if(s=="OR")t[i]=2;
        else if(s=="XOR")t[i]=3;
        else if(s=="NOT")t[i]=4;
        if(t[i]&&t[i]<4){
            cin>>ch[i][0]>>ch[i][1];
            f[ch[i][0]]=f[ch[i][1]]=i;
        }
        else if(t[i]==4){
            cin>>ch[i][0];
            f[ch[i][0]]=i;
        }
        else cin>>ans[i];
    }
    for(int i=1;i<=n;++i)if(!f[i])r=i;
    ope(r);
    dfs(r,2);
    for(int i=1;i<=n;++i)if(!t[i])putchar(48+out[i]);
	//system("pause");
	return 0;
}