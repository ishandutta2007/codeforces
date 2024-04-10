#include<cstdio>
#include<set>
const int N=200005;
int n,a[N],k,t;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        std::set<long long> st;
        for(int i=1;i<=n;i++){
            scanf("%d",a+i);
            st.insert(a[i]);
        }
        bool flag=0;
        for(int i=1;!flag&&i<=n;i++)
            if(st.count((long long)a[i]+k)) flag=1;
        puts(flag?"YES":"NO");
    }
    return 0;
}