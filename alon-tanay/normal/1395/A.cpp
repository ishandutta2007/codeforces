#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    long int r,g,b,w,min_color, even_sum;
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> t;
    for(int i = 0; i < t; i ++) {
        cin >> r >> g >> b >> w;
        min_color = min(min(r,g),b);
        even_sum = ((r-min_color)%2+(g-min_color)%2+(b-min_color)%2+(w+min_color)%2);
        if(even_sum == 2 || (even_sum == 3 && min_color == 0)) {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
    }
    return 0;
}