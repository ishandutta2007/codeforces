#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctgmath>
#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second

vector<int> v, vv, vvv;

int b[31];

void pr(int x){
    int flag = 1;
    printf("%d\n",x);
    for(int i=0;i<v.size();i++){
        if(flag && v[i]==x) flag = 0;
        else printf("%d\n",v[i]);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int t;
        scanf("%d",&t);
        v.pb(t);
        vvv.pb(t);
        for(int j=0;j<31;j++){
            if(t&(1<<j)) b[j]++;
        }
    }
    for(int j=30;j>=0;j--){
        if(b[j]==1){
            vv.clear();
            for(int i=0;i<vvv.size();i++){
                vv.push_back(vvv[i]);
            }
            vvv.clear();
            for(int i=0;i<vv.size();i++){
                if(vv[i]&(1<<j)){
                    vvv.push_back(vv[i]);
                }
            }
            if(vvv.size()==0){
                pr(vv[0]);
                return 0;
            }
        }
    }
    pr(vvv[0]);
    return 0;
}