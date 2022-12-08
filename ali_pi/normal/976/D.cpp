#include<bits/stdc++.h>
using namespace std;
const  int maxn = 1000 + 10;
int a[maxn];
vector<pair<int,int> > ans;
int n;

int main(){
    cin>>n;
    for(int i = 1; i <= n; i ++) cin>>a[i];
    int l = 1, r = n, st = 1, ends = a[n] + 1;
    while(l <= r){
        for(int i = 1; i <= a[l] - a[l-1]; i ++){
            for(int j = st+1; j <= ends; j ++){
                ans.push_back(make_pair(st,j));
            }
            st ++;
        }
        l++;
        ends = a[--r] + 1;
    }
    cout<<ans.size()<<endl;
    for(int i = 0; i < ans.size(); i ++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}