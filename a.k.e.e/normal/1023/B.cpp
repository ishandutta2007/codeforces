#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
const int MAXN=300005;

ll n,k;

int main()
{
    cin>>n>>k;
    if(k<=n+1)cout<<(k-1)/2<<endl;
    else cout<<max((2*n-k+1)/2,0ll)<<endl;
    return 0;
}