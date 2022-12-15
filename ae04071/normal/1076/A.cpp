#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef pair<lli,int> pli;

int n;
char str[200100];

int main(){
    scanf("%d%s",&n,str);
    for(int i=0;i<n-1;i++)if(str[i]>str[i+1]){
        for(int j=0;j<i;j++)printf("%c",str[j]);
        for(int j=i+1;j<n;j++)printf("%c",str[j]);
        return 0;
    }
    str[n-1]=0;
    printf("%s\n",str);
    return 0;
}