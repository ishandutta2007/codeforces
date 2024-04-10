#include <cstdio>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <bitset>
#include <cmath>
#include <set>
using namespace std;
#define LL long long
#define CLR(x) memset(x,0,sizeof(x))
#define typec double
#define sqr(x) ((x)*(x))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const double eps=1e-10;
int dblcmp(typec d) {
    if (fabs(d)<eps)
       return 0;
    return (d>0)?1:-1;
}
const int N=500;
const int M = 300;
const int inf=100000000;
int n,m,T,top,cnt,l;
int stack[N*M];
char a[N][M];
char str[M],b[M];
int main() {
    scanf("%d",&n);top=0;cnt=0;
    memset(stack,0,sizeof(stack));
    l=0;
    while (n--){
          scanf("%s",str);
          if (strcmp(str,"pwd")==0){
             for (int i=0;i<top;++i)
                 printf("/%s",a[stack[i]]);
                 printf("/\n");
          }
          else{
               memset(str,0,sizeof(str));
               scanf("%s",str);
               str[strlen(str)]='/';
               int len =strlen(str);
               l=0;int i=0;
               if (str[0]=='/'){
                  top=0;
                  ++i;
               }
               for (;i<len;++i){
                   if (str[i]=='/'){
                      if (strcmp(a[cnt],"..")==0){
                         if (top) --top;
                      }
                      else stack[top++]=cnt;
                      l=0;
                      ++cnt;
                   }
                   else a[cnt][l++]=str[i];
               }
          }
    }
    return 0;
}