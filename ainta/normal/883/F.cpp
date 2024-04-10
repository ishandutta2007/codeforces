#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
map<string,int>Map;
char p[110];
int n, chk[110], res;
int main(){
    int i, j, k;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",p);
        for(j=0;p[j];j++);
        int L = j;
        for(j=L-1;j>=0;j--){
            if(p[j]=='u'){
                for(k=L;k>j;k--)p[k] = p[k-1];
                p[j]=p[j+1]='o';
                L++;
            }
        }
        p[L] = 0;
        for(j=0;j<L;j++)chk[j]=0;
        int ck = 0;
        for(j=L-1;j>=0;j--){
            if(p[j]=='h')ck = 1;
            else if(p[j]=='k'){
                if(ck)chk[j]=1;
            }
            else ck = 0;
        }
        int c = 0;
        for(j=0;j<L;j++){
            if(!chk[j])p[c++] = p[j];
        }
        p[c] = 0;
        if(!Map.count(p)){
            Map[p] = ++res;
        }
    }
    printf("%d\n",res);
}