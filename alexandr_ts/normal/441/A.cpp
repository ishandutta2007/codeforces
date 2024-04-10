#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;

vector <int> an;

int main()
{
    ll n, qua;
    ll t;
    ll ans = 0;
    cin >> n >> qua;
    for(int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        bool er = false;
        for(int j = 0; j < k; j++)
        {
            cin >> t;
            if(t < qua)
                er = true;
        }
        if(er)
            an.push_back(i + 1);
    }
    cout << an.size() << endl;
    for(int i = 0; i < an.size(); i++)
        cout << an[i] << " ";
    return 0;

}