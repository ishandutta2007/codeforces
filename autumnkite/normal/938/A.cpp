#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#define LL long long
#define For(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define DFor(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define cross(i,a) for(int i=hd[(a)];i;i=pr[i])
using namespace std;
inline LL Max(LL a,LL b){return a>b?a:b;}
inline LL Min(LL a,LL b){return a<b?a:b;}
inline LL read(){
    LL x=0;int ch=getchar(),f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-') f=-1,ch=getchar();
    while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
    return x*f;
}
inline void write(LL x){
    if (x<0) putchar('-'),x=-x;
    if (x>=10) write(x/10),putchar(x%10+'0');
    else putchar(x+'0');
}
#define N 105
int n;char a[N];string A;
int let(char c){
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y';
}
int check(){
    For(i,0,A.size()-2) if(let(A[i])&&let(A[i+1])) return i;
    return -1;
}
int main(){
//#define ONLINE_JUDGE
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    n=read(),scanf("%s",a);A=string(a);
    /*while(~check()){
        int sum=0,j=0;
        For(i,0,A.size()-1) if(let(A[i])){
            sum++;
            if(sum==2) {j=i;break;}
        }
        A.erase(j,1);
    }*/
    for(int i=check();~i;i=check()) A.erase(i+1,1);
    printf("%s",A.c_str());
    return 0;
}