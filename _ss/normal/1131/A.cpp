#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll maxn=1e5+1;
ll w1,h1,w2,h2;
int main()
{
    cin>>w1>>h1>>w2>>h2;
    cout<<w1*2+h1*2+6+(h2-1)*2;
    return 0;
}