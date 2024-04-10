#include <iostream>

#include <stdio.h>

#include <limits.h>

#include <float.h>

#include <math.h>

#include <algorithm>

#include <cstdlib>

#include <memory.h>

#include <vector>

#include <queue>

#include <stack>

#include <set>

#include <map>

#include <time.h>

#include <string.h>

#include <cmath>

#include <iomanip>

#include <string>

#include <sstream>

#include <fstream>

#include <assert.h>

using namespace std;

#define M_PI 3.14159265358979323846

#define mp make_pair

#define pb push_back

#define ll long long

#define ull unsigned ll

#define pii pair<int,int>

#define pll pair<ll,ll>

#define all(x) x.begin(),x.end()

int n,k,x,s;

vector<int> p;

ll first;

void check(){

    for (int i=0;i<k;i++){

        x=i;s=0;

        while ((s<8)&&(x!=0)){x=p[x];s++;}

        if (s==8)return;

    }

    first++;

}

void put(int d){

    if (d==k){

        check();

    }else{

        for (p[d]=0;p[d]<k;p[d]++)

            put(d+1);

    }

}

int main()

{

    //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

    cin>>n>>k;

    p.resize(k);

    put(0);

    for (ll i=1;i<=n-k;i++)

        first=(first*(n-k))%1000000007;

    cout<<first<<endl;

    return 0;

}