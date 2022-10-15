#include <iostream>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0);
    long long n, a, b;
 
    cin >> n >> a >> b;
    if (6*n <= a*b)
        cout << a*b << "\n" << a << " " << b << "\n";
    else {
        bool f = 0;
        if (a > b)
        {
            swap(a, b);
            f = 1;
        }
        
        long long SQ = 1e18, a1, b1, tmpb;
        for(long long i = a; i*i <= 6*n; ++i) {
            tmpb = 6*n / i;
            if (tmpb * i < 6*n) tmpb++;
            
            if (tmpb < b) continue;
            
            if (tmpb * i < SQ) {
                SQ = tmpb * i;
                a1 = i;
                b1 = tmpb;
            }
        }
        
        if (f)
            swap(a1, b1);
        
        cout << SQ << "\n" << a1 << " " << b1 << "\n";
    }
 
    return 0;
}