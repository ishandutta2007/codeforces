#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int rec[n][2];
    for(int i=0;i<n;i++) cin >> rec[i][0] >> rec[i][1];
    bool order=1;
    int prev=max(rec[0][0],rec[0][1]);
    for(int i=1;i<n;i++)
    {
        int current=max(rec[i][0],rec[i][1]);
        if(current<=prev)
        {
            prev=current;
            continue;
        }
        current=min(rec[i][0],rec[i][1]);
        if(current<=prev)
        {
            prev=current;
            continue;
        }
        order=0;
        break;
    }
    if(order) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}