#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int N=300005;
int t,n;
char s[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        int len=strlen(s);
        int vis[30]={0};
        vector<char> v;
        int flag=0,cnt=0;
        for(int i=0;s[i];i++){
            if(!flag){
                if(vis[s[i]-'a']){
                    if(v[0]!=s[i]) goto NO;
                    flag=cnt=1;
                }
                else{
                    vis[s[i]-'a']=1;
                    v.push_back(s[i]);
                }
            }
            else if(v[cnt++%v.size()]!=s[i]) goto NO;
        }
        puts("YES");
        continue;
NO:
        puts("NO");
    }
    return 0;
}