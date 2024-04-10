#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector< pair<long,long> > v;
long n,i;
pair<long,long> e;

int main()
{
    cin >> n;
    for(i=1;i<=n;i++) {
        cin >> e.first >> e.second;
        v.push_back(e);
    }

    sort(v.begin(),v.end());

    for(i=1;i<n;i++){
        if((v[i-1].first != v[i].first)&&(v[i-1].second > v[i].second)){
            cout << "Happy Alex";
            return 0;
        }
    }

    cout << "Poor Alex";
    return 0;
}