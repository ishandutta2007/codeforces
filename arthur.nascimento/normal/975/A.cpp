#include <bits/stdc++.h>
#define maxn 600600
#define dec AAAAAAA
using namespace std;

char str[10010];

main(){
    int n;
    scanf("%d",&n);
    set<int> s;
    while(n--){
        scanf(" %s",str);
        int t = strlen(str);
        int u =0 ;
        for(int i=0;i<t;i++)
            u |= (1<<str[i]-'a');
        s.insert(u);
        
    }
    
    printf("%d\n",s.size());
}