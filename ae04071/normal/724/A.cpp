#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli = long long;
using pii = pair<int,int>;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

char str[30];
int get() {
    if(str[0]=='m') return 0;
    else if(str[0]=='t' && str[1]=='u') return 1;
    else if(str[0]=='w') return 2;
    else if(str[0]=='t') return 3;
    else if(str[0]=='f') return 4;
    else if(str[1]=='a') return 5;
    else return 6;
}

int main() {
    scanf("%s",str);
    
    int a=get();
    
    scanf("%s",str);
    int b=get();

    if(a>b) b+=7;
    if(b-a==3 || b-a==2 || b-a==0) puts("YES");
    else puts("NO");
    
    return 0;
}