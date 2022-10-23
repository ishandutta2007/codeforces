//
//  main.cpp
//  cf
//
//  Created by Dong Truong on 6/28/19.
//  Copyright  2019 Dong Truong. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;
#define maxn 1000001
#define pb push_back
#define long long long

struct elem
{
    long gt,st;
};

long n,m,kq[maxn];elem a[maxn],b[maxn];
bool cmp(elem a,elem b)
{
    return a.st<b.st;
}
void nhap()
{
    cin>>n>>m;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i].st;
        a[i].gt=i;
    }
    sort (a+1,a+n+1,cmp);
    for (int i=1;i<=m;++i)
        cin>>b[i].st>>b[i].gt;
    sort(b+1,b+m+1,cmp);
}
void sol()
{
    long sum=0,id=1;
    for (int i=1;i<=n;++i)
    {
        while (a[i].st>=b[id].st && id<=m)
        {
            sum+=b[id].gt;
            ++id;
        }
        //cout<<sum<<" ";
        kq[a[i].gt]=sum;
    }
    for (int i=1;i<=n;++i)
        cout<<kq[i]<<" ";
}
int main(int argc, const char * argv[]) {
    //freopen("a.inp","r",stdin);
    nhap();
    sol();
    return 0;
}