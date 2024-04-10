#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    set<int> pos;
    multiset<int> num;
    for(int o=0;o<n;o++)
    {
        int r;
        cin >> r;
        int temp;
        for(int i=0;i<r;i++)
        {
            cin >> temp;
            pos.insert(temp);
            num.insert(temp);
        }
    }
    for(set<int>::iterator it=pos.begin();it!=pos.end();it++)
    {
        if((int)num.count(*it)==n) cout << *it << " ";
    }
    cout << endl;
    return 0;
}