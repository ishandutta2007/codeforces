#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n=0;
    cin>>n;

    vector<int> a(n+1,0);

    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=a[i-1];
    }

    int m=0;
    cin>>m;

    int x;
    while(m--){
        cin>>x;
        cout<<lower_bound(a.begin()+1,a.end(),x)-a.begin()<<'\n';
    }

    return 0;
}