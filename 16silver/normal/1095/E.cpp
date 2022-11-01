#include <cstdio>
char s[1000011];
int main(){
    int n,tot=0;
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n;i++){
        if(s[i]=='(') tot++;
        else tot--;
    }
    if(tot != 2 && tot != -2){
        printf("0\n");
        return 0;
    }
    if(tot == 2){
        int tmp = 0;
        int ans1;
        for(int i=0;i<n;i++){
            if(s[i]=='(') tmp++;
            else tmp--;
            if(tmp == 1) ans1 = i;
            else if(tmp < 0){
                printf("0\n");
                return 0;
            }
        }
        int ans2 = 0;
        for(int i=ans1+1;i<n;i++){
            if(s[i]=='(') ans2++;
        }
        printf("%d\n",ans2);
    }
    else{
        int tmp = 0;
        int ans1;
        for(int i=n-1;i>=0;i--){
            if(s[i]==')') tmp++;
            else tmp--;
            if(tmp == 1) ans1 = i;
            else if(tmp < 0){
                printf("0\n");
                return 0;
            }
        }
        int ans2 = 0;
        for(int i=0;i<ans1;i++){
            if(s[i]==')') ans2++;
        }
        printf("%d\n",ans2);
    }
}