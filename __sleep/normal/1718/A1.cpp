#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
const int N=100005;
int t,n,a[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ans=n;
        set<int> st;
        st.insert(0);
        for(int i=1;i<=n;i++){
            scanf("%d",a+i);
            a[i]^=a[i-1];
            if(st.count(a[i])) --ans,st.clear(),st.insert(a[i]=0);
            else st.insert(a[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}