#include<cstdio>
#include<algorithm>
char p[600];
bool v[200];
int main(){
    int i, j;
    scanf("%s",p);
    for(i=0;p[i];i++){
        for(j='a';j<p[i];j++){
            if(!v[j]){
                printf("NO\n");
                return 0;
            }
        }
        v[p[i]]=true;
    }
    printf("YES\n");
}