#include<bits/stdc++.h>
using namespace std;
int N;
vector<string> a;
vector<int> lc;
int main()
{
    cin >> N;
    for(int i=0; i<N; ++i)
    {
        string x;
        cin >> x;
        a.push_back(x);
    }
    for(int i=N-2; i>=0; --i)
    {
        int cut = a[i].size();
        for(int j=0; j<a[i].size(); ++j)
        {
            if(a[i][j]<a[i+1][j])
            {
                cut = a[i].size();
                break;
            }
            if(a[i][j]>a[i+1][j])
            {
                cut = j;
                break;
            }
            
        }
        a[i] = a[i].substr(0, cut);
    }
    for(auto x: a) cout << x << endl;
    return 0;
}