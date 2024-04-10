#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#define maxN 100011

long n,i,last,v,r;
char s[maxN];

void change(long i,long j){
    char tmp = s[i]; s[i] = s[j]; s[j] = tmp;
}

int main()
{
    scanf("%s",s+1); last = -1;
    n = strlen(s+1); r = s[n]-'0';
    for(i=1;i<=n;i++){
        v = s[i] - '0';
        if(v%2==0){
            if(v<r){
                change(i,n); r = -1;
                break;
            }
            last = i;
        }
    }

    if(r!=-1){
        if(last!=-1){
            change(last,n);
            r = -1;
        }
    }

    if(r!=-1){
        printf("-1");
    } else {
        printf("%s",s+1);
    }

    return 0;
}