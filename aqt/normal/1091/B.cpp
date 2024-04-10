#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
    cin >> N;
    int xo = 0, yo = 0;
    cin >> xo >> yo;
    for(int i = 2; i<=N; i++){
        int x, y;
        cin >> x >> y;
        if(x < xo){
            xo = x;
            yo = y;
        }
        else if(x == xo && y < yo){
            xo = x;
            yo = y;
        }
    }
    int xc, yc;
    cin >> xc >> yc;
    for(int i = 2; i<=N; i++){
        int x,y;
        cin >> x >> y;
        if(x > xc){
            xc = x;
            yc = y;
        }
        else if(x == xc && y > yc){
            xc = x;
            yc = y;
        }
    }
    cout << xo + xc << " " << yo + yc << endl;
}