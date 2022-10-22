#include <bits/stdc++.h>

using namespace std;

int main()
{
    int nOps;
    cin >> nOps;
    
    // 0 .. 20000
    int y = 0;
    bool fail = false;
    
    for (int i = 0; i < nOps; i++)
    {
        int count;
        string dir;
        cin >> count >> dir;
        
        if (dir != "South" && dir != "North")
        {
            if (y == 0 || y == 20000)
                fail = true;
            
            continue;
        }
        
        if (dir == "North")
        {
            y -= count;
            if (y < 0)
                fail = true;
        }
        else
        {
            y += count;
            if (y > 20000)
                fail = true;
        }
    }
    
    if (y != 0)
        fail = true;
    
    cout << (fail ? "NO" : "YES") << endl;
    
    return 0;
}