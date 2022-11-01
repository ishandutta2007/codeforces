#include <bits/stdc++.h>
using namespace std;
int pp[1000001];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=2;i<1000001;){
        for(int j=i*2;j<=1000001;j+=i) pp[j] = i;
        for(i++;pp[i];i++);
    }
    int ans = n;
    for(int i=0;i<pp[n];i++){
        ans = min(ans, (n-i) - pp[n-i] + 1);
    }
    printf("%d\n",ans);
}