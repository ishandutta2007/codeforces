#include<cstdio>
#include<set>
#include<vector>
using namespace std;
const int N=15;
int t,n;
int a[N];
set<int> st;
vector<int> v;
int main(){
    scanf("%d",&t);
    while(t--){
        st.clear();
        bool flag=0;
        scanf("%d",&n);
        st.insert(0);
        for(int i=0;i<n;i++){
            scanf("%d",a+i);
            if(a[i]<0) a[i]=-a[i];
            if(st.count(a[i])) flag=1;
            v.clear();
            for(auto x:st){
                if(st.count(x+a[i])) flag=1;
                v.push_back(x+a[i]);
            }
            for(auto x:v)
                st.insert(x);
            st.insert(a[i]);
        }
        puts(flag?"YES":"NO");
    }
    return 0;
}