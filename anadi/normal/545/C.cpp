#include <bits/stdc++.h>

#define st first
#define nd second

using namespace std;

pair<int,int> t[100007];

const int INF=2*(1e9+1);

int main() {
    int n;
    scanf("%d", &n);
    int last=-INF, w=0;
    for(int i=1;i<=n;++i)
        scanf("%d %d", &t[i].st, &t[i].nd);
    t[n+1]=make_pair(INF,0);
    for(int i=1;i<=n;++i){
        if(last<t[i].st-t[i].nd){
            last=t[i].st;
            ++w;
        }
        else{
            if(t[i].st+t[i].nd<t[i+1].st){
                last=t[i].st+t[i].nd;
                ++w;
            }
            else
                last=t[i].st;
        }
    }
    printf("%d\n", w);
    return 0;
}