#include <bits/stdc++.h>
using namespace std;

char str[1000100];
int n;

int main() {
    scanf("%s",str);
    n=strlen(str);

    string ans;
    char ch=-1;
    for(int i=0,j=n-1;i<=j;i+=2,j-=2) {
        if(j-i+1<4) {
            ch=str[i];
            break;
        }
        
        int f=0;
        for(int a=i;a<i+2 && !f;a++)for(int b=j;b>j-2;b--) if(str[a]==str[b]) {
            f=1;
            ans.push_back(str[a]);
            break;
        }
    }
    printf("%s",ans.c_str());
    if(ch!=-1) printf("%c",ch);
    reverse(ans.begin(),ans.end());
    printf("%s\n",ans.c_str());

    return 0;
}