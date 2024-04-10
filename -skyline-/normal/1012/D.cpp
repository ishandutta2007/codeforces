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
int a[2][400005],ans,res[500005][2],p,q=1,n,m,cnt1,cnt2;
void out(){
    cout<<ans<<endl;
    for(int i=1;i<=ans;++i)cout<<res[i][0]<<' '<<res[i][1]<<endl;
    exit(0);
}
void work(){
    int x=a[p][n],y=a[q][m];
    while(n>1||m>1){
        while(n>1&&x==a[p][n-1])--n;
        while(m>1&&y==a[q][m-1])--m;
        if(n==1&&m==1) break;
        ++ans;
        res[ans][0]=n-1,res[ans][1]=m-1;
        swap(p,q);
        swap(n,m);
    }
}
int main(){
    string S,T;
    cin>>S>>T;
    n=S.size(),m=T.size();
    for(int i=1;i<n;++i)if(S[i-1]!=S[i])++cnt1;
    for(int i=1;i<m;++i)if(T[i-1]!=T[i])++cnt2;
    if(!cnt1&&!cnt2){
        if(S[0]==T[0]){
            cout<<1<<endl;
            cout<<0<<' '<<m<<endl;
        }
        else{
            cout<<0<<endl;
        }
        return 0;
    }
    if(abs(cnt1-cnt2)>1){
        for(int _=1;_<=1;++_){
        ++ans;
        int cnt=0;
        if(!cnt2){
            for(int i=1;i<n;++i){
                if(S[i]!=S[i-1])++cnt;
                if(cnt>=(cnt1+1)/2){
                    cnt=i-1;
                    break;
                }
            }
            res[1][0]=cnt+1;
            if(S[cnt]!=T[0])res[1][1]=m;
            break;
        }
        if(!cnt1){
            for(int i=1;i<m;++i){
                if(T[i]!=T[i-1])++cnt;
                if(cnt>=(cnt2+1)/2){
                    cnt=i-1;
                    break;
                }
            }
            res[1][1]=cnt+1;
            if(T[cnt]!=S[0])res[1][0]=n;
            break;
        }
        int k=0;
        if(cnt2<cnt1){
            for(int i=1;i<m;++i){
                if(T[i]!=T[i-1]){
                    k=i-1;
                    break;
                }
            }
            bool ok=0;
            for(int i=1;i<n;++i){
                if(S[i]!=S[i-1]){
                    ++cnt;
                    int x=cnt+cnt2-2,y=cnt1-cnt;
                    if(T[0]==S[i]&&abs(x-y)<=1){
                        cnt=i-1;
                        ok=1;
                        break;
                    }
                }
            }
            if(!ok){
                cnt=0;
                for(int i=1;i<n;++i){
                    if(S[i]!=S[i-1]){
                        ++cnt;
                        int x=cnt+cnt2-2,y=cnt1-cnt;
                        if(T[0]==S[i]&&abs(x-y)<=2){
                            cnt=i-1;
                            ok=1;
                            break;
                        }
                    }
                }
            }
            if(!ok){
                cnt=0;
                for(int i=1;i<n;++i){
                    if(S[i]!=S[i-1]){
                        ++cnt;
                        int x=cnt+cnt2-2,y=cnt1-cnt;
                        if(abs(x-y)<=1){
                            cnt=i-1;
                            ok=1;
                            break;
                        }
                    }
                }
            }
            
            res[1][0]=cnt+1;
            res[1][1]=k+1;
            break;
        }
        if(cnt2>cnt1){
            for(int i=1;i<n;++i){
                if(S[i]!=S[i-1]){
                    k=i-1;
                    break;
                }
            }
            bool ok=0;
            for(int i=1;i<m;++i){
                if(T[i]!=T[i-1]){
                    ++cnt;
                    int x=cnt+cnt1-2,y=cnt2-cnt;
                    if(S[0]==T[i]&&abs(x-y)<=1){
                        cnt=i-1;
                        ok=1;
                        break;
                    }
                }
            }
            if(!ok){
                cnt=0;
                for(int i=1;i<m;++i){
                    if(T[i]!=T[i-1]){
                        ++cnt;
                        int x=cnt+cnt1-2,y=cnt2-cnt;
                        if(S[0]==T[i]&&abs(x-y)<=2){
                            cnt=i-1;
                            ok=1;
                            break;
                        }
                    }
                }
            }
            if(!ok){
                cnt=0;
                for(int i=1;i<m;++i){
                    if(T[i]!=T[i-1]){
                        ++cnt;
                        int x=cnt+cnt1-2,y=cnt2-cnt;
                        if(abs(x-y)<=1){
                            cnt=i-1;
                            ok=1;
                            break;
                        }
                    }
                }
            }
            
            res[1][0]=k+1;
            res[1][1]=cnt+1;
            break;
        }
        
        }
        string s="",t="";
        for(int i=0;i<res[1][1];++i)s+=T[i];
        for(int i=res[1][0];i<n;++i)s+=S[i];
        for(int i=0;i<res[1][0];++i)t+=S[i];
        for(int i=res[1][1];i<m;++i)t+=T[i];
        S=s,T=t;
    }
    cnt1=cnt2=0;
    for(int i=1;i<n;++i)if(S[i-1]!=S[i])++cnt1;
    for(int i=1;i<m;++i)if(T[i-1]!=T[i])++cnt2;
    if(cnt1==0&&cnt2==0&&S[0]!=T[0]){
        out();
        return 0;
    }
    n=S.size(),m=T.size();
    for(int i=1;i<=n;++i)a[0][i]=S[i-1];
    for(int i=1;i<=m;++i)a[1][i]=T[i-1];
    if(a[0][n]!=a[1][m]){
        work();
        out();
        return 0;
    }
    cnt1=cnt2=0;
    for(int i=1;i<n;++i)if(S[i-1]!=S[i])++cnt1;
    for(int i=1;i<m;++i)if(T[i-1]!=T[i])++cnt2;
    ++ans;
    if(cnt1==0&&cnt2==0){
        res[ans][0]=n;
        res[ans][1]=0;
        out();
        return 0;
    }
    if(cnt1>cnt2){
        int l=n-1;
        while(S[l]==S[l-1])--l;
        res[ans][0]=l;
        res[ans][1]=m;
    }
    else{
        int l=m-1;
        while(T[l]==T[l-1])--l;
        res[ans][0]=n;
        res[ans][1]=l;
    }
    for(int _=1;_<=1;++_){
        string s="",t="";
        for(int i=0;i<res[ans][1];++i)s+=T[i];
        for(int i=res[ans][0];i<n;++i)s+=S[i];
        for(int i=0;i<res[ans][0];++i)t+=S[i];
        for(int i=res[ans][1];i<m;++i)t+=T[i];
        S=s,T=t;
    }
    n=S.size(),m=T.size();
    for(int i=1;i<=n;++i)a[0][i]=S[i-1];
    for(int i=1;i<=m;++i)a[1][i]=T[i-1];
    work();
    out();
 //	system("pause");
	return 0;
}