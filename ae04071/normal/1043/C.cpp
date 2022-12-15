#include <bits/stdc++.h>
using namespace std;

char str[1010];
int n;

int main(){
    scanf("%s",str);
    n=strlen(str);

    vector<int>ans;
    for(int i=n-1,lst=1;i>=0;i--){
        if((str[i]-'a')^lst) ans.push_back(1),lst^=1;
        else ans.push_back(0);
    }
    reverse(ans.begin(),ans.end());
    for(auto &v:ans)
        printf("%d ",v);

    return 0;
}