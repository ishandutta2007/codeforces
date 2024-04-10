#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    
    int curTriangles = 2 * a - 1;
    int nb = 0;
    int dr = 1, ga = 1;
    
    while(c != 0)
    {
        if(f != 0)
            f--;
        else
            e--;
        
        if(b != 0)
            b--;
        else
            c--;
            
        curTriangles += (dr + ga);
        nb += curTriangles;
        
        if(dr == 0)
            dr = -1;
        if(ga == 0)
            ga = -1;
        
        if(b == 0 && ga != -1)
            ga = 0;
        if(f == 0 && dr != -1)
            dr = 0;
    }
    
    cout << nb << endl;
    return 0;
}