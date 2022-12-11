#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll=long long;
const int N=200005,P=1000000007;
int a[N];
char s[N],ans[N];
void work(){
    int n,k;
    cin>>n>>k>>s;
    int num[26]={0},p=n/k;
    for(int i=0;i<n;i++){
        num[s[i]-'a']++;
        ans[i]='a';
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<num[i]&&j<k;j++){
            if(ans[j]==i+'a'&&ans[j]<p+'a') ++ans[j];
        }
    }
    ans[k]=0;
    puts(ans);
}
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) work();
    return 0;
}