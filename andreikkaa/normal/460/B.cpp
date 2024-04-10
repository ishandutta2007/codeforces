#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    long long r = 0, r_;
    vector<long long> o;
    for(long long i = 0; i <= 81; ++i)
    {
        r = b;
        for(int j = 1; j <= a; ++j)
            r *= i; 
        r += c;
        //cout << r << "!" <<endl;
        r_ = r;
        if(!(0 < r and r < 1e+9))
            continue;
        long long sum = 0;
        while(r > 0)
        {
            sum += r % 10;
            r /= 10;
        }
        //
        if(sum == i)
        {
            o.push_back(r_);
        }
    }
    cout << o.size() << endl;
    for(long long i : o)
        cout << i << " ";
}