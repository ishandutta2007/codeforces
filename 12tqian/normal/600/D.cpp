#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600;
long double dist(long double x1, long double y1, long double x2, long double y2){
    return (pow(x1-x2, 2) + pow(y1-y2, 2));
}
long double sector(long double r, long double a){
    long double triangle = cos(a) * sin(a) * r *r;
   // cout<< a << endl;
    long double other = a * r*r;
    return other - triangle;
}
long double mins(long double x, long double y){
    if(x<y){
        return x;
    }
    return y;
}
int main(){
    long double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2>> y2>>r2;
    cout << fixed << setprecision(100);
    long double d = dist(x1, y1, x2, y2);
    if(pow(r1 + r2,2)<=d){
        cout << 0;
        return 0;
    }
    if(d <= (r1 - r2)*(r1 - r2)){
        cout << PI * pow(mins(r1, r2), 2);
        return 0;
    }
    d = sqrt(d);
 //   cout << h << endl;
    long double angle1 = acos((r1*r1 + d*d - r2*r2)/(2*r1 *d));
    long double angle2 = acos((r2*r2 + d*d - r1*r1)/(2*r2 *d));
    //cout << angle1 << " " << angle2 << endl;
    long double fin = sector(r1, angle1) + sector(r2, angle2);
    
    cout << fin << endl;
    return 0;
}