#include <cstdio>
#include <algorithm>
using namespace std;
char s[111];
int a[100],b[100];
int n;
int cnt(){
    int r=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1') r++;
    }
    return r;
}
int main(){
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i],&b[i]);
    }
    int ans = cnt();
    for(int t=1;t<127;t++){
        for(int i=0;i<n;i++){
            if(t>=b[i] && (t-b[i])%a[i]==0){
                s[i] = (s[i]^1);
            }
        }
        ans = max(ans,cnt());
    }
    printf("%d\n",ans);
}