#include<stdio.h>
int n, c[26];
char p[201000];
int main(){
    int i, r = 0;
    scanf("%d",&n);
    n=2*n-2;
    scanf("%s",p);
    for(i=0;i<n;i++){
        if(p[i]<='Z')
        {
            if(c[p[i]-'A']==0){
                r++;
                c[p[i]-'A']++;
            }
            c[p[i]-'A']--;
        }
        else{
            c[p[i]-'a']++;
        }
    }
    printf("%d\n",r);
}