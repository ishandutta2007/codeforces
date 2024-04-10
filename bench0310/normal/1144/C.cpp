#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    map<int,int> m;
    vector<int> one,two;
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        if(m.find(a)==m.end())
        {
            m[a]=1;
            one.push_back(a);
        }
        else if(m[a]==1)
        {
            m[a]++;
            two.push_back(a);
        }
        else
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    sort(one.begin(),one.end());
    sort(two.begin(),two.end());
    reverse(two.begin(),two.end());
    cout << "YES" << endl;
    cout << one.size() << endl;
    for(int i=0;i<(int)one.size();i++) cout << one[i] << " ";
    cout << endl;
    cout << two.size() << endl;
    for(int i=0;i<(int)two.size();i++) cout << two[i] << " ";
    cout << endl;
    return 0;
}