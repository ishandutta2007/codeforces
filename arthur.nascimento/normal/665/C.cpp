#include <bits/stdc++.h>
#define maxn 300300
using namespace std;

char s[maxn];

int main() {
    scanf(" %s",s);
    int n = strlen(s);
    s[n] = '-';
    for(int i=1;i<n;i++){
        if(s[i] == s[i-1]) while(s[i] == s[i-1] || s[i] == s[i+1]){
            s[i]++;
            if(s[i] == 'z'+1) s[i] = 'a';
        }
    }
    s[n] = 0;
    printf("%s\n",s);
}