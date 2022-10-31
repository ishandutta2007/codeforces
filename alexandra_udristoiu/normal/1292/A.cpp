#include<iostream>
using namespace std;
int n, q, x, y, nr;
int d[3][100005];
int main(){
    cin>> n >> q;
    for(; q; q--){
        cin>> x >> y;
        if(d[x][y] == 1){
            d[x][y] = 0;
            nr -= d[3 - x][y - 1] + d[3 - x][y] + d[3 - x][y + 1];
        }
        else{
            d[x][y] = 1;
            nr += d[3 - x][y - 1] + d[3 - x][y] + d[3 - x][y + 1];
        }
        if(nr == 0){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
}