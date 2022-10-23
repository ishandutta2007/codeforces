#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+1;

int main()
{
    double l,h;
    cin>>h>>l;
    double x=(l*l-h*h)/(h*2);
    printf("%0.12lf",x);
    return 0;
}