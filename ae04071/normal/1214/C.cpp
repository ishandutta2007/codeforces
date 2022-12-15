#include <bits/stdc++.h>
using namespace std;

int n;
char str[200100];

int main() {
    scanf("%d%s",&n,str);
    
    int c=0,f=0;
    for(int i=0;i<n;i++) {
        if(str[i] == '(') c++;
        else c--;

        if(c==-1) {
            if(f) {
                puts("No");
                return 0;
            }
            f=1;
            c=0;
        }
    }
    if(c-f!=0) {
        puts("No");
    } else puts("Yes");
    return 0;
}