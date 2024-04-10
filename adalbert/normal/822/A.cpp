#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <memory.h>
#include <string.h>
#include <complex>
#include <queue>
#include <cstdlib>
#include <ctime>
#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define pb push_back
#define left einrdonbwrjnbo
#define right ejrngkeijvbr
#define pb push_back

#define fast    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef long double ld;

const int arr=9e5+10;
#define int ll

signed main()
{
    int a,b;
    cin>>a>>b;
    a=min(a,b);
    int ans=1;
    for (int i=1;i<=a;i++)
        ans*=i;
    cout<<ans;
}