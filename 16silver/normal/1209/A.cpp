#include <cstdio>
#include <algorithm>
using namespace std;
int a[100];
int chkd[100];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    int ans = 0;
    for(int i=0;i<n;i++){
        if(chkd[i]==0){
            ans++;
            chkd[i]=1;
            for(int j=i;j<n;j++){
                if(a[j]%a[i]==0) chkd[j]=1;
            }
        }
    }
    printf("%d\n",ans);
}