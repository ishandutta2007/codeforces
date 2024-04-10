#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long n,k,x,i;
vector<pair<long,long> > v;

int main()
{
    cin >> n >> k;
    for(i=1;i<=n;i++){
        cin >> x;
        v.push_back(make_pair(x,i));
    }
    sort(v.begin(),v.end());

    i=-1;
    while(i<n-1 && k >= v[i+1].first){
        k -= v[++i].first;
    }

    cout << i+1 << '\n';
    while(i>=0) {
        cout << v[i--].second << ' ';
    }

    return 0;
}