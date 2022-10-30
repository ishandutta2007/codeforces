#include<cstring>
#include<cstdio>
#include<algorithm>
#define N 1000100
using namespace std;
char s[N];
int ra[N],rb[N];
int main(){
    int a,b,i,n,r;
    ra[0]=0;
    scanf("%s",s+1);
    scanf("%d %d",&a,&b);
    for(i=1;s[i];i++){
        ra[i]=(ra[i-1]*10+s[i]-'0')%a;
    }
    n=i-1;
    rb[n+1]=0;
    for(i=n,r=1;i>0;i--,r=r*10%b){
        rb[i]=(rb[i+1]+r*(s[i]-'0'))%b;
    }
    for(i=1;i<n;i++){
        if(ra[i]==0&&rb[i+1]==0&&s[i+1]!='0'){
            break;
        }
    }
    if(i<n){
        puts("YES");
        char tmp=0;
        swap(tmp,s[i+1]);
        printf("%s\n",s+1);
        swap(tmp,s[i+1]);
        printf("%s\n",s+i+1);
    }
    else{
        puts("NO");
    }
    return 0;
}