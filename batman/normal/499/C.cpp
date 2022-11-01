#include <iostream>
#include <cmath>

using namespace std;

long double x1,x2,y11,y2 , x3,y3;
long double a,b,c;
long double d1,d2,d3;
int n,sum;

int main(){
    cin >> x1 >> y11;
    cin >> x2 >> y2;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a >> b >> c;

        x3 = (x1 + x2)/2;
        y3 = (y11 + y2)/2;

        d1 = abs((a*x1 + b * y11 + c) * (a*x1 + b * y11 + c) / ((a*a + b*b)) );
        d2 = abs((a*x2 + b * y2 + c) * (a*x2 + b * y2 + c) / ((a*a + b*b)) );
        d3 = abs((a*x3 + b * y3 + c) * (a*x3 + b * y3 + c) / ((a*a + b*b)) );

        if(d1 + d2  > 4 * d3)
            sum++;
    }
    cout << sum << endl;
    return 0;
}