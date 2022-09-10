#include<iostream>
#include<vector>
#include<cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long int LL;

pair<LL,LL> P[100005];

int main()
{
    LL n,r,a;
    cin >> n >> r >> a;
    a*=n;
    LL suma=0LL;
    for(int i=0;i<n;++i){
        cin >> P[i].second >> P[i].first;
        suma+=P[i].second;
    }
    sort(P,P+n);
    LL w=0LL;
    for(int i=0;suma<a;++i){
        if((suma+r-P[i].second)>a){
            w+=P[i].first*(a-suma);
            break;
        }
        suma+=r-P[i].second;
        w+=P[i].first*(r-P[i].second);
    }
    cout << w;
    return 0;
}