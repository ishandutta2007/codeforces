#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=300005;
int t,n;
char s[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        int len=strlen(s);
        int sum=0,mn=1e9;
        if(len&1){
            for(int i=0;s[i];i++){
                sum+=s[i]-'a'+1;
            }
            mn=min(s[len-1],s[0])-'a'+1;
            if(len==1) printf("Bob %d\n",sum);
            else printf("Alice %d\n",sum-2*mn);
        }
        else{
            for(int i=0;s[i];i++){
                sum+=s[i]-'a'+1;
            }
            printf("Alice %d\n",sum);
        }
    }
    return 0;
}