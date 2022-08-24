#include<cstdio>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
map<string,int>Map;
int n;
char p[110];
int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",p);
        if(Map.count(p)){
            printf("YES\n");
        }
        else printf("NO\n");
        Map[p] = 1;
    }
}