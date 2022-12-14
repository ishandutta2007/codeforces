#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll n,k,a[1000],i;
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n >> k;
    n%=6;
    a[k]=1;
    for(i=n;i>0;i--)
    {
        if(i%2==0)swap(a[1],a[2]);else swap(a[0],a[1]);
    }
    for(i=0;i<3;i++)if(a[i]==1)
    {
        cout << i << endl;
        return 0;
    }

  return 0;
}