#include<cstdio>
#include<algorithm>
#include<deque>
using namespace std;
int t, n,a,z,ans;
int main(){
    scanf("%d", &t);
    while(t--){
        ans = 0;
        deque<int> v;
        scanf("%d", &n);
        for (int i = 1; i <= n;i++){
            scanf("%d", &a);
            v.push_back(a);
        }
        // puts("!");
        while(!v.empty() &&*v.rbegin()==0){
            // printf("%d\n", v.size());
            v.pop_back();
        }
        while(!v.empty()&&*v.begin()==0)
            v.pop_front();
        for(auto a:v){
            if(a==0) ans |= 2;
            else
                ans |= 1;
        }
        if(ans==1)
            puts("1");
        else if(ans==2||ans==0)
            puts("0");
        else
            puts("2");
    }
    return 0;
}